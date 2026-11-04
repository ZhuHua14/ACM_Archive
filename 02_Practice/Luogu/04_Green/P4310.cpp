#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e6 + 5;
const int MAXLOG = 25;

ll n,a[MAXN],f[MAXLOG],pre[MAXLOG],maxf[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ll maxa = -1;
    memset(f,0,sizeof(f));
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        maxa = max(maxa,a[i]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 25; j++){
            if((ll(1 << j) & a[i]) != 0){
                f[j] = maxf[pre[j]] + 1;
                pre[j] = i;
            }
            maxf[i] = max(maxf[i],f[j]);
        }
        // for(int j = 0; j < 25; j++){
        //     cout << f[i][j] << ' ';
        // }
        // cout << endl;
    }
    cout << maxf[n];
    return 0;
}