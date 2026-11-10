// P1775 石子合并（弱化版）
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 305;

int f[MAXN][MAXN],a[MAXN],n,sum[MAXN];

int main(){
    cin >> n;
    memset(f,0x3f,sizeof(f));
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        f[i][i] = 0;
    }
    for(int len = 2; len <= n; len++){
        for(int l = 1; l + len - 1 <= n; l++){
            int r = l + len - 1;
            for(int k = l; k < r; k++){
                f[l][r] = min(f[l][r],f[l][k] + f[k + 1][r] + sum[r] - sum[l - 1]);
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}