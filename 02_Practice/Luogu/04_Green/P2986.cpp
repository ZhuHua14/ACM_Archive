#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 5;
struct Edge{
    ll from,to,val;

    Edge(ll _from,ll _to,ll _val): from(_from),to(_to),val(_val) {};
    Edge(){};
};


vector<Edge> edge[MAXN];
ll n,cnt[MAXN],subcnt[MAXN],f[MAXN];

void init1(ll u,ll fa){
    subcnt[u] = cnt[u];
    for(int i = 0; i < edge[u].size(); i++){
        if(edge[u][i].to != fa) init1(edge[u][i].to,u);
    }
    for(int i = 0; i < edge[u].size(); i++){
        if(edge[u][i].to != fa) subcnt[u] += subcnt[edge[u][i].to];
    }
}

void init2(ll u,ll fa){
    for(int i = 0; i < edge[u].size(); i++){
        if(edge[u][i].to != fa) init2(edge[u][i].to,u);
    }
    for(int i = 0; i < edge[u].size(); i++){
        if(edge[u][i].to != fa) f[u] += f[edge[u][i].to] + subcnt[edge[u][i].to] * edge[u][i].val;
    }
}

void dfs(ll u,ll fa){
    for(int i = 0; i < edge[u].size(); i++){
        if(edge[u][i].to != fa){
            f[edge[u][i].to] = f[u] + (subcnt[1] - subcnt[edge[u][i].to]) * edge[u][i].val - subcnt[edge[u][i].to] * edge[u][i].val;
            dfs(edge[u][i].to,u);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> cnt[i];
    }
    ll nowf,nowt,v;
    for(int i = 1; i < n; i++){
        cin >> nowf >> nowt >> v;
        edge[nowf].push_back(Edge(nowf,nowt,v));
        edge[nowt].push_back(Edge(nowt,nowf,v));
    }
    init1(1,0);
    init2(1,0);
    dfs(1,0);
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for(int i = 1; i <= n; i++){
        ans = min(ans,f[i]);
    }
    cout << ans << endl;
    return 0;
}