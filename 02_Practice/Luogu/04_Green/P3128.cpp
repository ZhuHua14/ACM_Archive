#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int MAXLOG = 20;
vector<ll> edge[MAXN];

ll n,k,cnt[MAXN],diff[MAXN],fa[MAXLOG][MAXN],depth[MAXN],lb[MAXN];
/*---------------------LCA-----------------------*/
void getlog(){
	for(int i = 2; i <= n; i++){
		lb[i] = lb[i / 2] + 1;
	}
}

void init1(int u,int fa){
	depth[u] = depth[fa] + 1;
	for(int i = 0; i < edge[u].size(); i++){
		if(edge[u][i] != fa) init1(edge[u][i],u);
	}
}

void init2(int u,int nowf){
	fa[0][u] = 	nowf;
	for(int i = 1; i <= lb[depth[u]]; i++){
		fa[i][u] = fa[i - 1][fa[i - 1][u]];
	}
	for(int i = 0; i < edge[u].size(); i++){
		if(edge[u][i] != nowf) init2(edge[u][i],u);
	}
}

void init(){
	getlog();
	init1(1,0);
	init2(1,0);
}

ll getlca(ll x,ll y){
	if(depth[x] > depth[y]) swap(x,y);
	ll d = depth[y] - depth[x];
	while(depth[y] > depth[x]){
		d = depth[y] - depth[x];
		y = fa[lb[d]][y];
	}
	if(x == y) return x;
	else{
		for(int i = MAXLOG; i >= 0; i--){
			if(fa[i][x] != fa[i][y]){
				x = fa[i][x];
				y = fa[i][y];
			}
		}
	}
	return fa[0][x];
}

/*-------------------------------------------*/
/*------------------diff---------------------*/
void update(ll x,ll y){
	ll lca = getlca(x,y);
	diff[x]	+= 1;
	diff[y] += 1;
	diff[lca] -= 1;
	diff[fa[0][lca]] -= 1;
}

ll ans = 0;
void marge(ll u,ll fa){
	cnt[u] = diff[u];
	for(int i = 0; i < edge[u].size(); i++){
		if(edge[u][i] != fa) marge(edge[u][i],u);
	}
	for(int i = 0; i < edge[u].size(); i++){
		if(edge[u][i] != fa) cnt[u] += cnt[edge[u][i]]; 
	}
	ans = max(ans,cnt[u]);
}
/*--------------------------------------------*/


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	ll from,to;
	for(int i = 1; i < n; i++){
		cin >> from >> to;
		edge[from].push_back(to);
		edge[to].push_back(from);
	}
	init();	
	for(int i = 1; i <= k ; i++){
		cin >> from >> to;
		update(from,to);
	}
	marge(1,0);
	cout << ans << endl;
	return 0;
}
