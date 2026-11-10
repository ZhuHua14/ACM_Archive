// P1049 [NOIP 2001 普及组] 装箱问题
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 35;
const int MAXV = 2e4 + 5;

int v,n,a[MAXN],f[MAXN][MAXV];

signed main(){
    cin >> v >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= v; j++){
            if(j < a[i]){
                f[i][j] = f[i - 1][j];
            }
            else f[i][j] = max(f[i - 1][j],f[i - 1][j - a[i]] + a[i]);
        }
    }
    cout << v - f[n][v] << endl;
    return 0;
}