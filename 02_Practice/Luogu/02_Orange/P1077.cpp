#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e6 + 7;
const int MAXN = 105;

//f[i][j] -> 摆放第i种花时占了前j个位置的方案总数

//f[i][j] = sigma(down: k = 0, up: min(j,a[i])) {f[i - 1][j - k]} % MOD

//边界条件: f[i][0] = 1 (1 <= i <= n)

int n,m,a[MAXN],f[MAXN][MAXN];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    f[0][0] = 1;
    for(int i = 1; i <= n; i++){
        f[i][0] = 1;
        for(int j = 1; j <= m; j++){
            for(int k = 0; k <= min(j,a[i]); k++){
                f[i][j] = (f[i][j] + f[i - 1][j - k]) % MOD;
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}