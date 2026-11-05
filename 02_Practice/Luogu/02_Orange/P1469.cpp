#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int ans,n,nowin;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>nowin;
		if(i == 1){
			ans = nowin;
		}
		else ans ^= nowin;
	}
	cout<<ans;
	return 0;
}