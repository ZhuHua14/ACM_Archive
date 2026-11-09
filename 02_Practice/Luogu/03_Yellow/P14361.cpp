//Author:ZhuHua14(luogu)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int INF = 1e9;
int T,n;
 
struct Node{
	int w[4],mdiff,mwp;
	
	void init(){
		mwp = 0,mdiff = INF;
		for(int i = 1; i <= 3; i++){
			if(w[i] > w[mwp]){
				mwp = i;
			}
		}
		for(int i = 1; i <= 3; i++){
			if(i != mwp){
				//cerr << i << ' ' << w[mwp] << ' ' << w[i] <<' ' << mdiff <<'\n'; 
				mdiff = min(mdiff,w[mwp] - w[i]);	
			}
		}
	}
	
	void print(){
		//cerr << "w:";
		for(int i = 1; i <= 3; i++){
			//cerr << w[i] << ' ';
		}
		//cerr << "mdiff: " << mdiff << ' ';
		//cerr << "mwp: " << mwp << '\n';  
	}
};

bool cmp(Node x,Node y){
	return x.mdiff < y.mdiff;
}

Node node[MAXN];
int cnt[4];

int main(){
	// freopen("club.in","r",stdin);
	// freopen("club.out","w",stdout);
//	freopen("club1.in","r",stdin);
//	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		memset(node,0,sizeof(node));
		memset(cnt,0,sizeof(cnt));
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> node[i].w[1] >> node[i].w[2] >> node[i].w[3];
			node[i].init();
		}
		sort(node + 1, node + 1 + n, cmp);
		int ans = 0;
		for(int i = 1; i <= n; i++){
			ans += node[i].w[node[i].mwp];
			cnt[node[i].mwp]++;
		}
		int flag = 0;
		for(int i = 1; i <= 3; i++){
			if(cnt[i] > n / 2){
				flag = i;
				//cerr << flag << '\n';
			}
		}
		if(flag != 0){
			for(int i = 1; i <= n; i++){
				if(node[i].mwp == flag){
					ans -= node[i].mdiff;
					cnt[flag]--;
//					node[i].print();
					//cerr << ans << '\n';
				}
				if(cnt[flag] <= n / 2) break;
			}	
		}
		cout << ans << '\n';
		//cerr << '\n';
	}
	return 0;
}
