#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t,n,xorsum;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		ll nowin;
		xorsum = 0;
		for(int i = 1; i <= n; i++){
			cin >> nowin;
			xorsum ^= nowin;
		}
		cout << (xorsum != 0? "Yes":"No") << endl;
	}
	return 0;
}
