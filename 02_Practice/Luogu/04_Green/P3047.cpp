#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXK = 25;

vector<ll> edge[MAXN];
ll n,k,c[MAXN],cnt[MAXN][MAXK],f[MAXN][MAXK];

void init(ll u,ll fa){
	for(int i = 0; i < MAXK; i++){
		cnt[u][i] = c[u];
	}
	for(int i = 0; i < edge[u].size(); i++){
		if(edge[u][i] != fa){
			init(edge[u][i],u);
		}
	}
	for(int i = 0; i < edge[u].size(); i++){
		if(edge[u][i] != fa){
			for(int j = 1; j < MAXK; j++){
				cnt[u][j] += cnt[edge[u][i]][j - 1];
			}
		}
	}
}

void dfs(ll u,ll fa){
	for(int i = 0; i < edge[u].size(); i++){
		if(edge[u][i] != fa){
			for(int j = 1; j < MAXK; j++){
				f[edge[u][i]][j] = f[u][j - 1] + cnt[edge[u][i]][j] - ((j - 2 >= 0)? cnt[edge[u][i]][j - 2]:0);				
			}
			dfs(edge[u][i],u);
		}
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ll nowf,nowt;
    for(int i = 1; i < n; i++){
    	cin >> nowf >> nowt;
    	edge[nowf].push_back(nowt);
    	edge[nowt].push_back(nowf);
    }
    for(int i = 1; i <= n; i++){
    	cin >> c[i];
    }
    init(1,0);
    for(int i = 1; i < MAXK; i++){
    	f[1][i] = cnt[1][i];
    }
    for(int i = 1; i <= n; i++){
    	f[i][0] = c[i];
	}
//    for(int i = 1; i <= n; i++){
//    	for(int j = 0; j < MAXK; j++){
//    		cout << cnt[i][j] << ' ';
//		}
//		cout << endl;
//	}
    dfs(1,0);
//    for(int i = 1; i <= n; i++){
//    	for(int j = 0; j <= MAXK; j++){
//    		cout << f[i][j] << ' ';
//		}
//		cout << endl;
//	}
    for(int i = 1; i <= n; i++){
    	cout << f[i][k] << endl;
    }
    return 0;
}