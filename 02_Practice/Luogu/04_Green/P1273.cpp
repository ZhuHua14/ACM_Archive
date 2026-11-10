// P1273 有线电视网
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 3e3 + 5;
const int MAXSZ = 3e4 + 5;
//预处理子树边权和sz_e，子树叶子和sz_l，子树叶子数cnt;
//f[u][i][k] -> 以u为根，选到第i个孩子时，选择k个叶子，可获得的最大利润
//f[u][i][k] = max(f[u][i - 1][k],f[u][i - 1][k - cnt[i]] + sz_e[i] + sz_l[i]);

struct Edge{
    ll from,to,val;
    
    Edge(ll _from,ll _to,ll _val): from(_from),to(_to),val(_val) {}
    Edge(){}
};

vector<Edge> edge[MAXN];
ll n,m,sz_e[MAXN],sz_l[MAXN],cnt[MAXN],f[MAXN][MAXN],cost[MAXN],t[MAXN];
bool isread[MAXN];

void init3(int u,int fa){
    for(int i = 0; i < edge[u].size(); i++){
        if(edge[u][i].to != fa) init3(edge[u][i].to,u);
    }
    for(int i = 0; i < edge[u].size(); i++){
        if(edge[u][i].to != fa) cnt[u] += cnt[edge[u][i].to];
    }
}

void dfs(int u,int fa){
    for(int i = 0; i < edge[u].size(); i++){
        if(edge[u][i].to != fa) dfs(edge[u][i].to,u);
    }
    for(int i = 0; i < edge[u].size(); i++){
        if(edge[u][i].to != fa){
            for(int j = cnt[u]; j >= 1; j--){
                for(int k = 1; k <= cnt[edge[u][i].to]; k++){
					if(k <= j) f[u][j] = max(f[u][j],f[u][j - k] + f[edge[u][i].to][k] - edge[u][i].val);
                }
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ll k,nowa,nowc;
    memset(f,-0x3f,sizeof(f));
    for(int i = 1; i <= n - m; i++){
        cin >> k;
        for(int j = 1; j <= k; j++){
            cin >> nowa >> nowc;
            edge[i].push_back(Edge(i,nowa,nowc));
            edge[nowa].push_back(Edge(nowa,i,nowc));
        }
    }
    for(int i = n - m + 1; i <= n; i++){
        cin >> cost[i];
        cnt[i] = 1;
        f[i][1] = cost[i];
    }
    for(int i = 1; i <= n; i++){
        f[i][0] = 0;
    }
    init3(1,0);
	dfs(1,0);
	int ans = 0;
	for(int i = 1; i <= m; i++){
		if(f[1][i] >= 0) ans = max(ans,i);
	}
    cout << ans << endl;
    return 0;
}
