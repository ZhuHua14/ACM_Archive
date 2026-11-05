#include<bits/stdc++.h>
#define ll long long
const int Mod=100003; 
using namespace std;
ll n,k,ans[100005];
int main(){
	cin>>n>>k;
	ans[0] = ans[1] = 1;
	for(ll i = 2;i <= n;i++){
		for(ll j = 1;j <= min(i,k);j++){
			ans[i] = (ans[i] % Mod + ans[i-j] % Mod) % Mod;
		}
	}
	cout<<ans[n]; 
	return 0;
} 