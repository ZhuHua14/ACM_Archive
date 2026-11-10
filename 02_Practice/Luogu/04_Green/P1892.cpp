// P1892 [BalticOI 2003] 团伙 (Day 2)
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
int n,m;
int fa[MAXN];
vector <int> fight[MAXN];

void init(){
	for(int nowp = 1; nowp <= n; nowp++){
		fa[nowp] = nowp;
		fight[nowp].clear();
	}
}

int find(int s){
	if(fa[s] == s){
		return s;
	}
	else{
		return fa[s] = find(fa[s]);
	}
}

void marge(int f,int s){
	int ff = find(f),fs = find(s);
	if(ff == fs){
		return;
	}
	else{
		fa[fs] = ff;
		return;
	}
}

/*void output(){
	for(int i = 1; i <= n; i++){
		cout<<i<<':'<<fa[i]<<' ';
	}
}*/
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	init();
	cin>>m;
	int p,q;
	char op;
	for(int i = 1; i <= m; i++){
		//cout<<i<<' '<<m<<endl;
		cin>>op;
		switch(op){
			case 'F':{
				cin>>p>>q;
				marge(p,q);
				//cout<<fa[p]<<' '<<fa[q]<<' '<<endl;
				break;
			}
			case 'E':{
				cin>>p>>q;
				fight[p].push_back(q);
				fight[q].push_back(p);
				for(int j = 0; j < fight[p].size(); j++){
					marge(q,fight[p][j]);
					//cout<<fight[p][j]<<endl;
				}
				for(int j = 0; j < fight[q].size(); j++){
					marge(p,fight[q][j]);
					//cout<<fight[q][j]<<endl;
				}
				break;
			}
		}
		//output();
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(fa[i] == i){
			//cout<<i<<' '<<fa[i]<<endl;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}