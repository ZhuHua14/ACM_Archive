#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 3e6 + 5;

ll inv[MAXN],n,p;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p;
    inv[1] = 1;
    cout << inv[1] << "\n";
    for(int i = 2; i <= n; i++){
    	inv[i] = (p - p / i) * (inv[p % i] ) % p;
    	cout << inv[i] << "\n";
    }
    return 0;
}