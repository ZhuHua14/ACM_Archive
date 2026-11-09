#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 5e5 + 5;
const int MAXLOG = 20;

ll n,m,s;
ll depth[MAXN],f[MAXN][MAXLOG];
ll lb[MAXN];
bool vis[MAXN];
vector<ll> edge[MAXN];

void init1(){
    lb[1] = 0;
    for(int i = 2; i <= n; i++){
        lb[i] = lb[i / 2] + 1;
    }
}

void init2(){
    queue<ll> q;
    q.push(s);
    ll nowtop;
    while(!q.empty()){
        nowtop = q.front();
        vis[nowtop] = 1;
        q.pop();
        for(int i = 0; i < edge[nowtop].size(); i++){
            if(vis[edge[nowtop][i]] == 0){
                q.push(edge[nowtop][i]);
                depth[edge[nowtop][i]] = depth[nowtop] + 1;
            }
        }
    }
}

void init3(int u,int fa){
    for(int i = 1; i <= lb[depth[u]]; i++){
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for(int i = 0; i < edge[u].size(); i++){
        if(edge[u][i] != fa){
            f[edge[u][i]][0] = u;
            init3(edge[u][i],u);
        }
    }
}

void init(){
    init1();
    init2();
    init3(s,-1);
}

int lca(int a,int b){
    if(depth[a] > depth[b]) swap(a,b);
    int dh = depth[b] - depth[a];
    while(depth[b] > depth[a]){
        dh = depth[b] - depth[a];
        b = f[b][lb[dh]];
    }
    if(a == b) return a;
    for(int j = MAXLOG - 1; j >= 0; j--){
        if(f[a][j] != f[b][j]){
            a = f[a][j];
            b = f[b][j];
        }
    }
    return f[a][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    ll from,to;
    for(int i = 1; i < n; i++){
        cin >> from >> to;
        edge[from].push_back(to);
        edge[to].push_back(from);
    }
    init();
    while(m--){
        cin >> from >> to;
        cout << lca(from,to) << endl;
    }
    return 0;
}