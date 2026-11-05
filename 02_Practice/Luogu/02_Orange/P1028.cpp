#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans[1000];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i/2;j++){
			ans[i] += ans[j];
		}
		ans[i]++;
	}
	cout<<ans[n];
	return 0;
} 