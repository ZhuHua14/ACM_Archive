#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 5e3 + 5;
const int MAXM = 5e3 + 5;
const int INF = 0x3f3f3f3f3f3f3f3f;

struct Edge{
	ll to,from,val;

	Edge(ll _to,ll _from, ll _val){
		to = _to;
		from = _from;
		val = _val;
	}

	Edge(){ }
};
vector<Edge> edge[MAXN];

ll n,m;
ll dis[MAXN];

void init(){
	for(int i = 1; i <= n; i++){
		edge[0].push_back(Edge(i,0,0));
	}
}

bool spfa(){
	ll cnt[MAXN];
	bool vis[MAXN];
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	memset(vis,0,sizeof(vis));
	queue<int> q;
	dis[0] = 0;
	q.push(0);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(auto e:edge[u]){
			if(dis[e.to] > dis[e.from] + e.val){
				dis[e.to] = dis[e.from] + e.val;
				cnt[e.to] = cnt[e.from] + 1;
				if(cnt[e.to] > n){
					return 1;
				}
				else{
					vis[e.to] = 1;
					q.push(e.to);
				}
			}
			if(cnt[e.to] > n){
				return 1;
			}
		}
	}
	return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    Edge nowin;
    for(int i = 1; i <= m; i++){
    	cin >> nowin.to >> nowin.from >> nowin.val;
    	edge[nowin.from].push_back(nowin);
    }
    init();
    if(spfa()){
    	cout << "NO";
    }
    else{
    	for(int i = 1; i <= n; i++){
    		cout << dis[i] << ' ';
    	}
    }
    cout << endl;
    return 0;
}