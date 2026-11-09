//tarjan 边双
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e5 + 5;

struct Edge{
    int u,v,w;

    Edge(){}

    Edge(int _u,int _v,int _w): u(_u) , v(_v) , w(_w) {}
};

vector<Edge> edge[MAXN];
vector<int> ecc[MAXN];
int n,m;
int dfn[MAXN],low[MAXN],ecccnt = 0,cnt = 0;

int st[MAXN],top = 0;

int pop(){
    return st[top--];
}

void push(int x){
    st[++top] = x;
}

void tarjan(int u,int fa){
    dfn[u] = low[u] = ++cnt;
    push(u);
    for(auto e : edge[u]){
        if(e.w == (fa ^ 1)) continue;
        if(!dfn[e.v]){
            tarjan(e.v,e.w);
            low[u] = min(low[u],low[e.v]);
        }
        else{
            low[u] = min(low[u],dfn[e.v]);
        }
    }
    //cerr << u << ' ' << low[u] << ' ' << dfn[u] << endl;
    if(low[u] == dfn[u]){
        //cerr << u << endl;
        ecccnt++;
        while(st[top] != u){
            ecc[ecccnt].push_back(pop());
        }
        ecc[ecccnt].push_back(pop());
        //cerr << top << endl;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int from,to;
    for(int i = 1 ;i <= m; i++){
        cin >> from >> to;
        edge[from].push_back(Edge(from,to,i * 2));
        edge[to].push_back(Edge(to,from,i * 2 ^ 1));
    }
    for(int i = 1; i <= n; i++){
        if(!dfn[i]){
            tarjan(i,0);
        }
    }
    cout << ecccnt << endl;
    for(int i = 1; i <= n; i++){
        if(!ecc[i].empty()){
            cout << ecc[i].size() << ' ';
            for(int p : ecc[i]){
                cout << p << ' ';
            }
            cout << endl;
        }
    }
   return 0;
}