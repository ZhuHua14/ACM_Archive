// P1219 [USACO1.5] 八皇后 Checker Challenge
#include<bits/stdc++.h>
const int MAXN = 100;
using namespace std;
int n,a[MAXN],map1[MAXN],map2[MAXN],map3[MAXN];
bool isSafe(int x,int y){
	return map1[y] + map2[x+y] + map3[x-y+20] == 0;
}
int ans;
void dfs(int k){
	if(k > n){
		ans++;
		if(ans <= 3){
			for(int i = 1;i <= n;i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
	}
	for(int i = 1;i <= n;i++){
		if(isSafe(k,i)){
			a[k] = i;
			map1[i] = map2[k+i] = map3[k-i+20] = 1;
			dfs(k+1);
			map1[i] = map2[k+i] = map3[k-i+20] = 0;
		}
	}
}
int main(){
	cin>>n;
	dfs(1);
	cout<<ans; 
	return 0;
} 