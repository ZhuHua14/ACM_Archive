// P2585 [ZJOI2006] 三色二叉树
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 5;

vector<ll> edge[MAXN];
string s;
ll len,vis = 0,f1[MAXN][3],f2[MAXN][3];

void dfs(int u){
	vis++;
	if(s[u] == '0') return;
	else if(s[u] == '1'){
		edge[u].push_back(u + 1);
		edge[u + 1].push_back(u);
		dfs(u + 1);
	}
	else if(s[u] == '2'){
		edge[u].push_back(u + 1);
		edge[u + 1].push_back(u);
		dfs(u + 1);
		edge[u].push_back(vis);
		edge[vis].push_back(u);
		dfs(vis);
	}
}

void dp(int u,int fa){
//	cout << u << ' ' << fa << endl;
	int s[2],cnt = 0;
	s[0] = s[1] = len;
	for(int i = 0; i < edge[u].size(); i++){
		if(edge[u][i] != fa){
			dp(edge[u][i],u);
			s[cnt] = edge[u][i];
			cnt++;
		}
	}
	f1[u][0] = max(f1[s[0]][1] + f1[s[1]][2],f1[s[0]][2] + f1[s[1]][1]) + 1;
	f1[u][1] = max(f1[s[0]][0] + f1[s[1]][2],f1[s[0]][2] + f1[s[1]][0]);
	f1[u][2] = max(f1[s[0]][1] + f1[s[1]][0],f1[s[0]][0] + f1[s[1]][1]);
	f2[u][0] = min(f2[s[0]][1] + f2[s[1]][2],f2[s[0]][2] + f2[s[1]][1]) + 1;
	f2[u][1] = min(f2[s[0]][0] + f2[s[1]][2],f2[s[0]][2] + f2[s[1]][0]);
	f2[u][2] = min(f2[s[0]][1] + f2[s[1]][0],f2[s[0]][0] + f2[s[1]][1]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	len = s.size();
	dfs(0);
	/*for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < edge[i].size(); j++){
			cout << i << ' ' << edge[i][j] << endl;
		}
	}*/
	dp(0,-1);
	cout << max(f1[0][0],max(f1[0][1],f1[0][2])) << ' ' << min(f2[0][0],min(f2[0][1],f2[0][2])) << endl;
	return 0;
}
