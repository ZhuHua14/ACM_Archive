#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 5;

vector<int> edge[MAXN];
bitset<MAXN> iscut;
int dfn[MAXN],low[MAXN],dft;
int cutcnt,n,m;

void tarjan(int u,int fa){
    dfn[u] = low[u] = ++dft;
    int scnt = 0;
    for(int v : edge[u]){
        if(!dfn[v]){
            scnt++;
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
            if(fa != u && low[v] >= dfn[u] && !iscut[u]){
                cutcnt++;
                iscut[u] = 1;
            }
        }
        else if(v != fa){
            low[u] = min(low[u],dfn[v]);
        }
    }
    if(fa == u && scnt >= 2 && !iscut[u]){
        cutcnt++;
        iscut[u] = 1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int x,y;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        if(!dfn[i]){
            tarjan(i,i);
        }
    }
    cout << cutcnt << endl;
    for(int i = 1; i <= n; i++){
        if(iscut[i]){
            cout << i << ' ';
        }
    }
    return 0;
}