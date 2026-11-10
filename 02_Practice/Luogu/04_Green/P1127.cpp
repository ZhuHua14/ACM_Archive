// P1127 词链
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 4;
struct Edge{
	int to,down;
	string value;
};

Edge create(int t,string val,int down){
	Edge c;
	c.to = t;
	c.value = val;
	c.down = down;
	return c;
}

int toInt(char x){
	return x - 'a' + 1;
}

vector<Edge> v[27];
int lnum[27],rnum[27];
string edge[MAXN];

void insert(int from,int to,string val,int down){
	v[from].push_back(create(to,val,down));
	//cout<<(v[from].end() - 1)->value<<'\n';
	lnum[from]++;
	rnum[to]++;
}

int fa[27],point[40],nowcnt;
void init(int i){
	fa[i] = i;
}
int find(int x){
	return (fa[x] == x)? x:(fa[x] = find(fa[x]));
}
void marge(int f,int s){
	int ff = find(f),fs = find(s);
	if(fs == ff){
		return;
	}
	fa[fs] = ff;
}
bool check(){
	int ans = 0;
	for(int i = 1; i <= 27; i++){
		if(fa[i] == i){
			ans++;
		}
	}
	if(ans != 1){
		return 1;
	}
	return 0;
}

string finalans[MAXN];
bool isRead[MAXN];
bool flag = 0;
int n;
void dfs(int nowp,int cnt,int pre){
	//cout<<nowp<<':';
	//cout<<' '<<cnt<<' '<<pre<<'\n';
	if(flag == 1) return;
	if(cnt == n){
	    flag = 1;
		for(int i = 1; i <= n; i++){
			cout<<finalans[i];
			if(i != n) cout<<'.';			
		}
		return;
	}
	for(int i = 0; i < v[nowp].size(); i++){
		if(isRead[v[nowp][i].down] == 0){
			//cout<<"    "<<isRead[i]<<' '<<v[nowp][i].value<<'\n';
			isRead[v[nowp][i].down] = 1;
			finalans[cnt + 1] = v[nowp][i].value;
			dfs(v[nowp][i].to,cnt + 1,v[nowp][i].down);
		}
	}
	isRead[pre] = 0;
	return;
}

int main(){
	cin >> n;
	string nowin;
	int nowf,nows;
	bool flagf = 0,flags = 0;
	for(int i = 1; i <= n; i++){
		cin >> nowin;
		edge[i] = nowin;
		nowf = toInt(nowin[0]);
		nows = toInt(nowin[nowin.size() - 1]);	
		if(fa[nowf] == 0) init(nowf);
		if(fa[nows] == 0) init(nows);
		//cout<<fa[nowf]<<' '<<fa[nows]<<' '<<'\n';
		marge(nowf,nows);
	}
	sort(edge + 1,edge + n + 1);
	for(int i = 1; i <= n; i++){
		nowin = edge[i];
		nowf = toInt(nowin[0]);
		nows = toInt(nowin[nowin.size() - 1]);
		insert(nowf,nows,nowin,i);		
	}
	if(check()){
		cout << "***";
		return 0;
	}
	//cout<<"p1c";
	int start = 1e2,end = 1e2;
	bool flagfr = 0,flage = 0;
	for(int i = 0; i <= 25; i++){
		if(lnum[i] - rnum[i] == 1){
			if(flagfr == 0){
				start = i;
				flagfr = 1;
			}
			else{
				cout << "***";
				return 0;
			}
		}
		else if(rnum[i] - lnum[i] == 1){
			if(flage == 0){
				end = i;
				flage = 1;
			}
			else{
				cout << "***";
				return 0;
			}
		}
		else if(lnum[i] == rnum[i]){
			continue;
		}
		else{
			cout << "***";
			return 0;
		}
	}
//	cout<<"p2c";
	if((flagfr ^ flage) != 0){
		cout << "***";
		return 0;
	}
	//cout<<"p3c";
	if(flagfr == 0 && flage == 0){
		start = toInt(edge[1][0]);
	}
    //cout<<"p4c\n";
	dfs(start,0,0);
	return 0;
}
/*HACK:
3
cc
ca
ad
*/