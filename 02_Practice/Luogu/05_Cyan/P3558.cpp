#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int INF = 0x3f3f3f3f;
int f[MAXN][3],n,a[MAXN];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i]++;/*real a[i] = a[i] - 1*/
    }
    memset(f,0x3f,sizeof(f));
    f[1][a[1]] = 0;
    for(int i = 2; i <= n; i++){
        if(a[i] == 0){
            f[i][0] = f[i - 1][0];
            f[i][2] = f[i - 1][2] + 2;
        }
        else if(a[i] == 1){
            f[i][0] = f[i - 1][0] + 1;
            f[i][1] = min(f[i - 1][0],f[i - 1][1]);
            f[i][2] = f[i - 1][2] + 1;
        }
        else if(a[i] == 2){
            f[i][0] = f[i - 1][0] + 2;
            f[i][1] = f[i - 1][0] + 1;
            f[i][2] = min(f[i - 1][0],min(f[i - 1][1],f[i - 1][2]));
        }
    }
    int ans = min(f[n][0],min(f[n][1],f[n][2]));
    if(ans >= INF) cout << "BRAK\n";
    else cout << ans << '\n';
    return 0;
}