#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e3 + 5;
const int MAXM = 1e4 + 5;
struct Node{
	int t,x,y;
};
Node node[MAXM];
int dist(int x1,int y1,int x2,int y2){
	return abs(x1 - x2) + abs(y1 - y2);
}

int n,m,f[MAXM];
signed main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> node[i].t >> node[i].x >> node[i].y;
		f[i] = 1;
	}
	int ans = 0;
	for(int i = 2; i <= m; i++){
		int fromx = node[i].x,fromy = node[i].y;
		for(int k = 1; k < i; k++){
			int nowx = node[k].x,nowy = node[k].y;
			if(dist(fromx,fromy,nowx,nowy) <= abs(node[i].t - node[k].t)){
				f[i] = max(f[i],f[k] + 1);
			}
			ans = max(f[i],ans);
		}
	}
	cout << ans;
	return 0;
}