#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXLOG = 15;

vector<ll> edge[MAXN];
ll n,f[MAXN][MAXLOG];

void dfs(ll u,ll fa){
    for(int i = 1; i < MAXLOG; i++){
        f[u][i] = i;
    }
    for(int i = 0; i < edge[u].size(); i++){
        if(edge[u][i] != fa) dfs(edge[u][i],u);
    }
    for(int i = 0; i < edge[u].size(); i++){
        if(edge[u][i] != fa){
            for(int j = 1; j < MAXLOG; j++){
                ll minf = 0x3f3f3f3f3f3f3f3f;
                for(int k = 1; k < MAXLOG; k++){
                    if(j != k){
                        minf = min(minf,f[edge[u][i]][k]);
                    }
                }
                f[u][j] += minf;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ll nowf,nowt;
    for(int i = 1; i < n; i++){
        cin >> nowf >> nowt;
        edge[nowf].push_back(nowt);
        edge[nowt].push_back(nowf);
    }
    dfs(1,0);
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for(int i = 1; i < MAXLOG; i++){
        ans = min(ans,f[1][i]);
    }
    cout << ans << endl;
    return 0;
}