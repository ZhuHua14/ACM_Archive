// P3146 [USACO16OPEN] 248 G
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 255;

int a[MAXN],n,f[MAXN][MAXN];

int main(){
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        f[i][i] = a[i];
        ans = max(ans,a[i]);
    }
    for(int len = 2; len <= n; len++){
        for(int l = 1; l + len - 1 <= n; l++){
            int r = l + len - 1;
            for(int k = l; k < r; k++){
                if(f[l][k] == f[k + 1][r] && f[l][k] > 0) f[l][r] = max(f[l][r],f[l][k] + 1);
            }
            ans = max(ans,f[l][r]);
        }
    }
    cout << ans << endl;
    return 0;
}