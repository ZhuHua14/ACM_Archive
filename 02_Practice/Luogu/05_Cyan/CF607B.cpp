#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 505;
//f[l][r] = max(f[l][r] , max(k = (nowl = (a[l] == a[r])? l + 1:l),(nowr = (a[l] == a[r])? r - 1:r)) f[nowl][k] + f[k + 1][nowr]);

int n,a[MAXN],f[MAXN][MAXN];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(f,0x3f,sizeof(f));
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int len = 1; len <= n; len++){
        for(int l = 1; l + len - 1 <= n; l++){
            int r = l + len - 1;
            if(a[l] == a[r]){
                if(len <= 2) f[l][r] = 1;
                else f[l][r] = min(f[l][r],f[l + 1][r - 1]);
            }
            for(int k = l; k < r; k++){
                f[l][r] = min(f[l][r],f[l][k] + f[k + 1][r]);
            }
        }
    }
    /*for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << ((f[i][j] == 0x3f3f3f3f3f3f3f3f)? -1:f[i][j]) << ' ';
        }
        cout << '\n';
    }*/
    cout << f[1][n] << endl;
    return 0;
}