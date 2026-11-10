// P2367 语文成绩
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXN = 5e6 + 5;

int a[MAXN],diff[MAXN],n,p;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
    	diff[i] = a[i] - a[i - 1];
    }
    int r,l,x;
	for(int i = 1; i <= p; i++){
		cin >> l >> r >> x;
		diff[l] += x;
		diff[r + 1] -= x;
	}
	int ans = 1e9;
	for(int i = 1; i <= n; i++){
		a[i] = a[i - 1] + diff[i];
		ans = min(a[i],ans);		
	}
	cout << ans << '\n';
    return 0;
}