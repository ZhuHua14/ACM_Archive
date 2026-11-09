#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1505;
const int INF = 1e9;
struct Edge{
	int to,val;
};
vector <Edge> v[MAXN];
int n,m,innum[MAXN],ans[MAXN]; 
signed main(){
	//freopen("in.txt","r",stdin);
	cin>>n>>m;
	int nowf;
	Edge nowin;
	for(int i = 1; i <= m; i++){
		cin>>nowf>>nowin.to>>nowin.val;
		v[nowf].push_back(nowin);
		innum[nowin.to]++;	
	}
	queue <int> q;
	for(int i = 2; i <= n; i++){
		ans[i] = -INF;
		if(innum[i] == 0){
			q.push(i);
		}
	}
	int nowtop;
	while(!q.empty()){
		nowtop = q.front();
		q.pop();
		for(int i = 0; i < v[nowtop].size(); i++){
			innum[v[nowtop][i].to]--;
			if(innum[v[nowtop][i].to] == 0){
				q.push(v[nowtop][i].to);
			}
		}
	}
	q.push(1);
	while(!q.empty()){
		nowtop = q.front();
		q.pop();
		if(ans[nowtop] == -INF) ans[nowtop] = 0;
		for(int i = 0; i < v[nowtop].size(); i++){
			//cout<<ans[nowtop] + v[nowtop][i].val<<' '<<ans[v[nowtop][i].to];
			ans[v[nowtop][i].to] = max(ans[v[nowtop][i].to],ans[nowtop] + v[nowtop][i].val);
			innum[v[nowtop][i].to]--;
			if(innum[v[nowtop][i].to] == 0){
				q.push(v[nowtop][i].to);
			}
		}
	}
	if(ans[n] != -INF)cout<<ans[n];
	else cout<<-1;
	return 0;
}