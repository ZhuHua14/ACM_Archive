// P1220 关路灯
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 55;
ll n,c,f[MAXN][MAXN][2],d[MAXN],w[MAXN],sum[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> c;
    for(int i = 1; i <= n; i++){
        cin >> d[i] >> w[i];
    }
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + w[i];
    }
    memset(f,0x3f,sizeof(f));
    f[c][c][0] = f[c][c][1] = 0;
    for(int len = 2; len <= n; len++){
        for(int l = 1; l + len - 1 <= n; l++){
            int r = l + len - 1;
            f[l][r][0] = min(f[l + 1][r][0] + (sum[n] - (sum[r] - sum[l])) * abs(d[l + 1] - d[l]),f[l + 1][r][1] + (sum[n] - (sum[r] - sum[l])) * abs(d[r] - d[l]));
            f[l][r][1] = min(f[l][r - 1][0] + (sum[n] - (sum[r - 1] - sum[l - 1])) * abs(d[r] - d[l]),f[l][r - 1][1] + ((sum[n] - (sum[r - 1] - sum[l - 1]))) * abs(d[r] - d[r - 1]));            
        }
    }
    cout << min(f[1][n][0],f[1][n][1]) << endl;
    return 0;
}