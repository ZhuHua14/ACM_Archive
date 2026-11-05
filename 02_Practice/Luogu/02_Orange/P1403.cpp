#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;

int n;

int main(){
	cin>>n;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += n / i;
	}
	cout<<ans;
	return 0;
}