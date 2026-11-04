//tarjan 强联通分量
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e4 + 5;

struct Edge{
    int u,v;

    Edge() {}
    Edge(int _u,int _v): u(_u),v(_v) {}

};

vector<Edge> edge[MAXN];
int n,m,cnt = 0;


int st[MAXN],top = 0;
bool instack[MAXN];

void push(int x){
    instack[x] = 1;
    st[++top] = x;
}

int pop(){
    instack[st[top]] = 0;
    return st[top--];
}

vector<vector<int>> scc;
int dfn[MAXN],low[MAXN],scccnt = 0;

void tarjan(int u,int fa){
    dfn[u] = low[u] = ++cnt;
    push(u);
    for(auto e : edge[u]){
        int v = e.v;
        if(!dfn[v]){
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
        }
        else if(instack[v] == 1){
            low[u] = min(low[u],dfn[v]);
        }
    }
    if(dfn[u] == low[u]){
        scccnt++;
        vector<int> s;
        while(st[top] != u){
            s.push_back(pop());
        }
        s.push_back(pop());
        sort(s.begin(),s.end());
        scc.push_back(s);
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
    }
    for(int i = 1; i <= n; i++){
        if(!dfn[i]) tarjan(i,0);
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