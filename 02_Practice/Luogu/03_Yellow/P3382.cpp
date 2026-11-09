#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const double EPS = 0.000001;
const int MAXN = 15;

ll n;
double l,r,a[MAXN];

double f(double x){
	double ans = 0.0;
	for(int i = 0; i <= n; i++){
		ans += a[i] * pow(x,i);
	}
	return ans;	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> l >> r;
	for(int i = n; i >= 0; i--){
		cin >> a[i];
	}
	while(r - l > EPS){
		double mid = (l + r) / 2;
		double lf = f(mid - EPS),rf = f(mid + EPS);
		if(lf > rf){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	cout << l << endl;
	return 0;
}
