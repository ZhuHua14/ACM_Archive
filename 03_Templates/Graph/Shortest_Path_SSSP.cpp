#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e4 + 5;
const int MAXM1 = 2e3 + 5;
const int MAXM2 = 5e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
struct Edge{
    ll from,to,val;

    Edge(ll _from,ll _to,ll _val){
        from = _from;
        to = _to;
        val = _val;
    }
};
vector<Edge> edge[MAXN];
void insert(Edge e){
    edge[e.from].push_back(e);
}

struct Node{
    ll cnt,dis;

    Node(ll _cnt,ll _dis){
        dis = _dis;
        cnt = _cnt;
    }

    bool operator>(const Node) const;
};

bool Node::operator>(const Node a) const{
    return dis > a.dis;
}
ll n,m,s;


void dijkstra(){
	priority_queue<Node,vector<Node>,greater<Node> > pq;
	ll dis[MAXN];
	bool vis[MAXN];
    pq.push(Node(s,dis[s]));
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s] = 0;
	while(!pq.empty()){
        int u = pq.top().cnt;
        pq.pop();
        if(vis[u] == 0){
            vis[u] = 1;
            for(int i = 0; i < edge[u].size(); i++){
                if(dis[edge[u][i].from] + edge[u][i].val < dis[edge[u][i].to]){
                    dis[edge[u][i].to] = dis[edge[u][i].from] + edge[u][i].val;
                    pq.push(Node(edge[u][i].to,dis[edge[u][i].to]));
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ((dis[i] == INF)? (ll(ll(1ll << 31) - 1)):dis[i])  << ' ';
    } 
}

bool bellman_fold(){
    ll dis[MAXN],cnt = 0;
    bool flag = 1;
    memset(dis,0x3f,sizeof(dis));
    dis[s] = 0;
	while(flag){
        flag = 0;
        cnt++;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < edge[i].size(); j++){
                if(dis[edge[i][j].from] + edge[i][j].val < dis[edge[i][j].to]){
                    dis[edge[i][j].to] = dis[edge[i][j].from] + edge[i][j].val;
                    flag = 1;
                }
            }
        }
        if(cnt >= n){
        	return 1;
        	break;
		}
    }
    for(int i = 1; i <= n; i++){
        cout << ((dis[i] == INF)? (ll(ll(1ll << 31) - 1)):dis[i])  << ' ';
    }
    return 0;
}

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
    for(int i = 1; i <= n; i++){
        cout << ((dis[i] == INF)? (ll(ll(1ll << 31) - 1)):dis[i])  << ' ';
    }
    return 0;
}

int main(){
	//freopen("P3371_2.in","r",stdin);
	//freopen("out.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    ll nowf,nowt,val;
    for(int i = 1; i <= m; i++){
        cin >> nowf >> nowt >> val;
        insert(Edge(nowf,nowt,val));
    }
    spfa();
    cout << endl;
    return 0;
}
