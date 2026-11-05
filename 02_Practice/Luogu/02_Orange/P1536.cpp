#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
int n,m;

int fa[MAXN],bot[MAXN];
void init(){
	for(int i = 1; i <= n; i++){
		fa[i] = i;
	}
	return;
}

int find(int x){
	if(x == fa[x]) return x;
	else{
		return fa[x] = find(fa[x]);
	}
}

void marge(int f,int s){
	int ff = find(fa[f]), fs = find(fa[s]);
	fa[fs] = ff;
}

int main(){
	int nowf,nows;
	while(true){
		cin>>n;
		init();
		if(n == 0) break;
		else{
			cin>>m;
			for(int i = 1; i <= m; i++){
				cin>>nowf>>nows;
				marge(nowf,nows);
			}
			int ans = 0;
			for(int i = 1; i <= n; i++){
				if(fa[i] == i){
					ans++;
				}
			}
			ans--;
			cout<<ans<<endl;
		}
	}
	return 0;
}