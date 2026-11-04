#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXA = 60;
const int MAXN = 262150;

ll a[MAXN],n,f[MAXA][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        f[a[i]][i] = i + 1;
        ans = max(ans,a[i]);
    }
    for(int i = 2; i <= 58; i++){
        for(int j = 1; j <= n; j++){
            if(f[i][j] == 0){
                f[i][j] = f[i - 1][f[i - 1][j]];
            }
            if(f[i][j] != 0){
                ans = max(ans,ll(i));
            }
        }
    }
    cout << ans << endl;
    return 0;
}