#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e6 + 5;

ll n,f[MAXN],cnt[MAXN],depth[MAXN];
vector<ll> edge[MAXN];

void init1(int u,int fa){
    cnt[u] = 1;
    for(int i = 0; i < edge[u].size(); i++){
        if(edge[u][i] != fa) {
            depth[edge[u][i]] = depth[u] + 1;
            init1(edge[u][i],u);
        }
    }
    for(int i = 0; i < edge[u].size(); i++){
        if(edge[u][i] != fa) cnt[u] += cnt[edge[u][i]];
    }
}

void dfs(int u,int fa){
    for(int i = 0; i < edge[u].size(); i++){
        if(edge[u][i] != fa){
            f[edge[u][i]] = f[u] + (cnt[1] - cnt[edge[u][i]]) - cnt[edge[u][i]];
            dfs(edge[u][i],u);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ll from,to;
    for(int i = 1; i < n; i++){
        cin >> from >> to;
        edge[from].push_back(to);
        edge[to].push_back(from);
    }
    depth[1] = 1;
    init1(1,0);
    // cout << cnt[1] << endl;
    // for(int i = 1; i <= n; i++){
    //     cout << cnt[i] << ' ';
    // }
    for(int i = 1; i <= n; i++){
        f[1] += depth[i];
    }
    dfs(1,0);
    ll ans = 0,pos = 0;
    for(int i = 1; i <= n; i++){
        if(ans < f[i]){
            ans = f[i];
            pos = i;
        }
    }
    cout << pos << endl;
    return 0;
}