#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MOD = 19260817;

ll a,b,x,y;

ll read(){
	ll res = 0;
	char c = getchar();
	while(!isdigit(c) && c != EOF)
        c = getchar();
	while(isdigit(c)){
		res *= 10;
		res += (c - '0');
		res %= MOD;
		c = getchar(); 
	}
	return res;
}

void exgcd(ll a,ll b,ll& x,ll& y){
	if(b == 0){
		x = 1;
		y = 0;
		return;
	}
	exgcd(b,a % b,x,y);
	int t = x;
	x = y;
	y = t - (a / b) * y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    a = read();
    b = read();
    // cout << a << ' ' << b << '\n' ;
	exgcd(b,MOD,x,y);
	cout << (a * x % MOD + MOD) % MOD;
    return 0;
}