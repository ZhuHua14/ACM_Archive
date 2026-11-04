#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int x,y,a,b;

void exgcd(int a,int b,int& x,int& y){
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
    cin >> a >> b;
    exgcd(a,b,x,y);
    x = (x % b + b) % b;
    cout << x;
	return 0;
}