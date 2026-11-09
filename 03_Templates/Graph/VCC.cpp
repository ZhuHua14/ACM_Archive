//tarjan 点双
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
int n,m,cnt = 0;

int st[MAXN],top = 0;
void push(int x){
    st[++top] = x;
}

int pop(){
    //cerr << st[top] << ' ';
    return st[top--];
}

void clear(){
    top = 0;
}

vector<int> dcc[MAXN];
int dfn[MAXN],low[MAXN],dcccnt = 0;

void tarjan(int u,int fa,int fan){
    dfn[u] = low[u] = ++cnt;
    int son = 0;
    push(u);
    for(auto e : edge[u]){
        if(e.w == (fa ^ 1) || e.v == fan) continue;
        if(!dfn[e.v]){
            son++;
            tarjan(e.v,e.w,u);
            low[u] = min(low[u],low[e.v]);
            if(low[e.v] >= dfn[u]){
                dcccnt++;
                while(st[top + 1] != e.v){
                    dcc[dcccnt].push_back(pop());
                }
                //cerr << "  " << st[top] << ' ' << u << endl; 
                dcc[dcccnt].push_back(u);
            }
        }
        else{
            low[u] = min(low[u],dfn[e.v]);
        }
    }
    if(son == 0 && fa == 0){
        dcccnt++;
        dcc[dcccnt].push_back(u);
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
        if(!dfn[i]) tarjan(i,0,0);
        clear();
    }
    cout << dcccnt << endl;
    for(int i = 1; i <= dcccnt; i++){
        cout << dcc[i].size() << ' ';
        for(int p : dcc[i]){
            cout << p << ' ';
        }
        cout << endl;
    }
    return 0;
}