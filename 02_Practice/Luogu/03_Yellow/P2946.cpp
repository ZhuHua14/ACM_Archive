#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e3 + 5;
const int MAXSUM = 2e8 + 5;
const int MOD = 1e8;
int n,F,r[MAXN],f[MAXN][MAXN];
//f[i ][j] = f[(i - 1)][j] + f[(i - 1)][j - r[i]];
//ans = sigma(down: i = 0; up: sigma(r) / F) f[n][i * F]
signed main(){
    cin >> n >> F;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> r[i];
        r[i] %= F;
    }
    for(int i = 1; i <= n; i++){
        f[i][r[i]] = 1;
        for(int j = 0; j < F; j++){
            //cout << j;
            f[i][j] = (f[i][j] + f[(i - 1)][j] + f[(i - 1)][(j - r[i] + F) % F]) % MOD;
        }
        //cout << endl;
    }
    cout << f[n][0] % MOD;
    return 0;
}