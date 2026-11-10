// P2016 战略游戏
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1.5e3 + 5;
vector<ll> edge[MAXN];
ll f[MAXN][2],n;

void dfs(ll u,ll fa){
	f[u][1] = 1;
	for(int i = 0; i < edge[u].size(); i++){
		if(edge[u][i] != fa) dfs(edge[u][i],u);
	}
	for(int i = 0; i < edge[u].size(); i++){
		if(edge[u][i] != fa){
			f[u][0] += f[edge[u][i]][1];
			f[u][1] += min(f[edge[u][i]][0],f[edge[u][i]][1]);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	memset(f,0,sizeof(f));
	ll nowr,k,to;
	for(int i = 0; i <= n - 1; i++){
		cin >> nowr >> k;
		for(int j = 1; j <= k; j++){
			cin >> to;
			edge[nowr].push_back(to);
			edge[to].push_back(nowr);
		}
	}
	dfs(0,-1);
	cout << min(f[0][0],f[0][1]) << endl;
	return 0;
}