// P11035 【MX-X3-T2】「RiOI-4」消えた夏の夢
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 5;
ll a,n,p;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> n >> p;
	for(int i = 1; i <= n; i++){
		cin >> a;
		if(a > 0){
			p += a;
		}
	}
	cout << p << endl;
	return 0;
}