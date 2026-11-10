// P1802 5 倍经验日
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e3 + 5;

struct Node{
	int lose,win,val;
};
Node node[MAXN];

int n,x,f[MAXN][MAXN];

signed main(){
	cin >> n >> x;
	for(int i = 1; i <= n; i++){
		cin >> node[i].lose >> node[i].win >> node[i].val;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= x; j++){
			if(j >= node[i].val){
				f[i][j] = max(f[i - 1][j] + node[i].lose,f[i - 1][j - node[i].val] + node[i].win);
			}
			else{
				f[i][j] = f[i - 1][j] + node[i].lose;
			}
		}
	}
	cout << f[n][x] * 5ll << endl;
	return 0;
}