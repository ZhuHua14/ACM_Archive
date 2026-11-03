#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const double EPS = 1e-6;

double chk(double p,ll month,ll ori){
	double rate = 1.0 / (1.0 + p);
	return ori * rate * (1 - pow(rate,month)) / (1 - rate);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll w0,w,m;
	cin >> w0 >> w >> m;
	double l = 0,r = 5,mid;
	while(r - l > EPS){
		mid = (l + r) / 2;
		cerr << l << ' ' << r << ' ' << chk(mid,m,w)<< '\n';
		if(chk(mid,m,w) < w0){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	l *= 100;
	printf("%.1f",l);
	return 0;
}