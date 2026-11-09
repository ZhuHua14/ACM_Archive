//kosaraju/双dfs 强联通分量
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e4 + 5;

struct Edge{
    int u,v;

    Edge() {}
    Edge(int _u,int _v): u(_u),v(_v) {}

};

vector<Edge> edge[MAXN],edge2[MAXN];
int n,m,cnt = 0;
bool vis[MAXN];

int st[MAXN],top = 0;

void push(int x){
    st[++top] = x;
}

int pop(){
    return st[top--];
}

vector<vector<int>> scc;
int scccnt = 0;

void dfs1(int u,int fa){
    vis[u] = 1;
    for(auto e : edge[u]){
        int v = e.v;
        if(!vis[v]) dfs1(v,u);
    }
    push(u);
}

void dfs2(int u,int fa){
    scc[scccnt - 1].push_back(u);
    vis[u] = 0;
    for(auto e : edge2[u]){
        if(vis[e.v]) dfs2(e.v,u);
    }
}

bool cmp(vector<int> a,vector<int> b){
    return a[0] <= b[0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int from,to;
    for(int i = 1; i <= m ; i++){
        cin >> from >> to;
        edge[from].push_back(Edge(from,to));
        edge2[to].push_back(Edge(to,from));
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs1(i,0);
    }
    while(top > 0){
        int t = pop();
        if(vis[t]){
            scccnt++;
            scc.push_back({});
            dfs2(t,0);
            sort(scc[scccnt - 1].begin(),scc[scccnt - 1].end());
        }
    }
    sort(scc.begin(),scc.end(),cmp);
    cout << scccnt << '\n';
    for(auto s : scc){
        for(auto p : s){
            cout << p << ' ';
        }
        cout << '\n';
    }
    return 0;
}