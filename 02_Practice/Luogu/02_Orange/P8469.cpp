// P8469 [Aya Round 1 D] 文文的数学游戏
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

ll n,a[MAXN];

// int gcd(int a,int b){
//     while(b != 0){
//         int tmp = b;
//         b = a % b;
//         a = tmp;
//     }
//     return a;
// }


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ll gcdm = a[1];
    for(int i = 2; i <= n; i++){
        gcdm = min(a[i],gcdm);
    }
    ll ans = 1;
    for(int i = 1; i <= n; i++){
        ans = ((ans % MOD) * (a[i] / gcdm) % MOD) % MOD;
    }
    cout << gcdm << ' ' << ans << endl;
    return 0;
}