#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e4 + 5;
const int MAXM = 1e5 + 5;

vector<int> edge[MAXN],edge2[MAXN];
int n,m,a[MAXN];

int dfn[MAXN],low[MAXN],dft;
int scc[MAXN],sccnt,sz[MAXN];
int st[MAXN],tp;
bitset<MAXN> instack;
int f[MAXN],ind[MAXN];

void push(int x){
	st[++tp] = x;
}

void pop(){
	instack[st[tp]] = 0;
	tp--;
}

void tarjan(int u){
	dfn[u] = low[u] = ++dft;	
	push(u);
	instack[u] = 1;
	for(int v : edge[u]){
		if(!dfn[v]){
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if(instack[v]){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(low[u] == dfn[u]){
		sccnt++;
		int temp;
		while(st[tp] != u){
			temp = st[tp];
			pop();
			sz[sccnt] += a[temp];
			scc[temp] = sccnt;
		}
		temp = st[tp];
		pop();
		sz[sccnt] += a[temp];
		scc[temp] = sccnt;
	}
}

void build(){
	for(int i = 1; i <= n; i++){
		for(int v : edge[i]){
			if(scc[i] != scc[v]){
				edge2[scc[i]].push_back(scc[v]);
				// cout << i << ' ' << scc[i] << ' ' << v << ' ' << scc[v] << endl;
				ind[scc[v]]++;
			}
		}
	}
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int from,to;
	for(int i = 1; i <= m; i++){
		cin >> from >> to;
		edge[from].push_back(to);
	}
	for(int i = 1; i <= n; i++){
		if(!dfn[i]) tarjan(i);
	}
	for(int i = 1; i <= sccnt; i++){
		f[i] = sz[i];
	}
	// for(int i = 1; i <= n; i++){
		// cout << scc[i] << ' ' << sz[i] << endl;
	// }
	build();
	// print();
	queue<int> q;
	int ans = 0;
	for(int i = 1; i <= sccnt; i++){
		// cout << ind[i] << ' ';
		if(ind[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		// cout << "OK\n";
		int temp = q.front();
		q.pop();
		for(int v : edge2[temp]){
			ind[v]--;
			if(ind[v] == 0){
				q.push(v);
			}
			f[v] = max(f[v],f[temp] + sz[v]);
// 			cout << temp << ' ' << f[v] << ' ' << f[temp] << ' ' << sz[v] << endl;
		}
	}
	for(int i = 1; i <= sccnt; i++){
		ans = max(ans,f[i]);
	}
	cout << ans;
	return 0;
}