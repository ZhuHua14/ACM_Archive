#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 105;

typedef struct Edge{
	int to,value;
}Edge;
vector<Edge> v[MAXN];

typedef struct Node{
	int num,c;
	bool ishead;
}Node;

int u[MAXN],incnt[MAXN],outcnt[MAXN],n,p,c[MAXN];
signed main(){
    //freopen("in.txt","r",stdin);
	cin >> n >> p;
	queue<Node> q;
	for(int i = 1; i <= n; i++){
		cin >> c[i] >> u[i];
        if(c[i] == 0) c[i] -= u[i];
	}
	Edge nowin;
	int nowfrom;
	for(int i = 1; i <= p; i++){
		cin >> nowfrom >> nowin.to >> nowin.value;
		v[nowfrom].push_back(nowin);
		incnt[nowin.to]++;
		outcnt[nowfrom]++;
	}
	for(int i = 1; i <= n; i++){
		if(incnt[i] == 0){
			q.push((Node){i,c[i],1});
		}
	}
	Node nowtop;
	while(!q.empty()){
		nowtop = q.front();
		q.pop();
		for(int i = 0; i < v[nowtop.num].size(); i++){
			if(nowtop.c > 0 || nowtop.ishead == 1) c[v[nowtop.num][i].to] += (v[nowtop.num][i].value * nowtop.c);
			//cout << v[nowtop.num][i].to << ' ' << c[v[nowtop.num][i].to] << '|';
			incnt[v[nowtop.num][i].to]--;
			if(incnt[v[nowtop.num][i].to] == 0){
				q.push((Node){v[nowtop.num][i].to,c[v[nowtop.num][i].to],0});
			}
		}
		//cout << endl;
	}
	bool flag = 1;
	for(int i = 1; i <= n; i++){
        //cout << i << ' ' << c[i] <<'|';
		if(outcnt[i] == 0 && c[i] > 0){
			flag = 0;
			cout << i << ' ' << c[i] << endl;
		}
	}
	if(flag) cout << "NULL" << endl;
	return 0;
}