#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 105;
int n,m,f[MAXN][MAXN];

vector<pair<int,int>> edge[MAXN];
void floyd(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
			}
		}
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> n >> m;
	int u,v,w;
	memset(f,0x3f,sizeof(f));
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		f[u][v] = min(f[u][v],w);
		f[v][u] = min(f[v][u],w);
	}
	for(int i = 1; i <= n; i++){
		f[i][i] = 0;
	}
	floyd();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << f[i][j] << ' ';
		}
		cout << endl;
	}
}