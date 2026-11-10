// P2014 [CTSC1997] 选课
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 305;
const int MAXSUM = 6e4 + 5;

ll val[MAXN],sz[MAXN],n,m,f[MAXN][MAXN];
vector<ll> edge[MAXN];

void init(ll u,ll fa){
	sz[u]++;
	for(int i = 0; i < edge[u].size(); i++){
		if(edge[u][i] != fa) init(edge[u][i],u);
	}
	for(int i = 0; i < edge[u].size(); i++){
		if(edge[u][i] != fa) sz[u] += sz[edge[u][i]];
	}
}

void init2(){
	for(int i = 0; i <= n; i++){
		f[i][1] = val[i];
	}
}

void dfs(int u,int fa){
    for(int i = 0; i < edge[u].size(); i++){
        if(edge[u][i] != fa) dfs(edge[u][i],u);
    }
    for(int i = 0; i < edge[u].size(); i++){
    	for(int j = m; j >= 0; j--){
    		for(int k = 0; k < j; k++){
    			if(edge[u][i] != fa) f[u][j] = max(f[u][j],f[u][j - k] + f[edge[u][i]][k]);
    		}
    	}
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    m++;
    ll nowf;
    for(int i = 1; i <= n; i++){
    	cin >> nowf >> val[i];
    	edge[nowf].push_back(i);
    	edge[i].push_back(nowf);
    }
    init(0,-1);
    init2();
    dfs(0,-1);
    cout << f[0][m] << endl;
    return 0;
}