// P3205 [HNOI2010] 合唱队
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e3 + 5;
const int MOD = 19650827;
int n,a[MAXN],f[MAXN][MAXN][2];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n; i++){
        cin >> a[i];
        f[i][i][0] = 1;
    }
    for(int len = 2; len <= n; len++){
        for(int l = 1; l + len - 1 <=n; l++){
            int r = l + len - 1;
            if(a[l] < a[l + 1]) f[l][r][0] = (f[l][r][0] % MOD + f[l + 1][r][0] % MOD) % MOD;
            if(a[l] < a[r]) f[l][r][0] = (f[l][r][0] %  MOD + f[l + 1][r][1] % MOD) % MOD;
            if(a[r] > a[r - 1]) f[l][r][1] = (f[l][r][1] % MOD + f[l][r - 1][1] % MOD) % MOD;
            if(a[r] > a[l]) f[l][r][1] = (f[l][r][1] % MOD + f[l][r - 1][0] % MOD) % MOD;
			f[l][r][0] %= MOD;
			f[l][r][1] %= MOD;

        }
    }
    cout << (f[1][n][0] + f[1][n][1]) % MOD << endl;
}