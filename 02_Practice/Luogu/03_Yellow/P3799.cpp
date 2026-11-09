#include<bits/stdc++.h>
#define int long long
const int MAXN = 1e5 + 5;
const int MAXA = 5e3 + 3;
const int MOD = 1e9 + 7; 
using namespace std;
int n,a[MAXN],bot[MAXA],ans,maxa;
signed main(){
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		bot[a[i]]++;
		maxa = max(maxa,a[i]);
	}
	int cnti = 0, cnts = 0;
	for(int i = 1; i <= maxa; i++){
		if(i >= 2 && bot[i] >= 2){
			cnti = ((bot[i] * (bot[i] - 1)) / 2) % MOD;
			for(int s = i; s * 2 >= i; s--){
				if(s == i - s){
					cnts = ((bot[s] * (bot[s] - 1)) / 2) % MOD;
				}
				else{
					cnts = (bot[s] * bot[i - s]) % MOD;
				}
			ans += (cnti * cnts) % MOD;
			}	
		}	
	}
	cout<<ans % MOD;
	return 0;
} 