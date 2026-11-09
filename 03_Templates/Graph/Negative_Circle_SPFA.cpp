#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e3 + 5;
const int MAXM = 3e3 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
struct Edge{
    ll from,to,val;

    Edge(ll _from,ll _to,ll _val){
        from = _from;
        to = _to;
        val = _val;
    }
    
    Edge(){
        from = 0;
        to = 0;
        val = 0;
    }
};
vector<Edge> edge[MAXN];

ll t,s = 1,n,m;

bool spfa(){
    ll dis[MAXN],cnt[MAXN];
    bool vis[MAXN];
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    dis[s] = 0;
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = 0; i < edge[u].size(); i++){
            if(dis[edge[u][i].from] + edge[u][i].val < dis[edge[u][i].to]){
                dis[edge[u][i].to] = dis[edge[u][i].from] + edge[u][i].val;
                cnt[edge[u][i].to] = cnt[edge[u][i].from] + 1;
                if(cnt[edge[u][i].to] > n){
                    return 1;
                }
                else{
                    vis[edge[u][i].to] = 1;
                    q.push(edge[u][i].to);
                }
            }
        }
    }
    return 0;
}

void init(){
    for(int i = 1; i <= n; i++){
        edge[i].clear();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        init();
        Edge nowin;
        for(int i = 1; i <= m; i++){
            cin >> nowin.from >> nowin.to >> nowin.val;
            edge[nowin.from].push_back(nowin);
            if(nowin.val >= 0){
                edge[nowin.to].push_back(Edge(nowin.to,nowin.from,nowin.val));
            }
        }
        cout << (spfa()? "YES":"NO") << endl;
    }
    return 0;
}
