// P2880 [USACO07JAN] Balanced Lineup G
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int MAXLOG = 25;
int n,q,a[MAXN],maxf[MAXN][MAXLOG],minf[MAXN][MAXLOG];

int lb[MAXN];
void getLog(){
    lb[1] = 0;
    lb[2] = 1;
    for(int i = 3; i <= MAXN; i++){
        lb[i] = lb[i / 2] + 1;
    }
}

void init(){
    getLog();
    for(int i = 1; i <= n; i++){
        maxf[i][0] = a[i];
        minf[i][0] = a[i];
    }
    for(int j = 1; j <= MAXLOG; j++){
        for(int i = 1; i + (1 << j) - 1 <= n; i++){
            minf[i][j] = min(minf[i][j - 1],minf[i + (1 << (j - 1))][j - 1]);
            maxf[i][j] = max(maxf[i][j - 1],maxf[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    init();
    int l,r;
    for(int i = 1; i <= q; i++){
        cin >> l >> r;
        int mid = lb[r - l + 1];
        int ans = max(maxf[l][mid],maxf[r - (1 << mid) + 1][mid]) - min(minf[l][mid],minf[r - (1 << mid) + 1][mid]);
        cout << ans << '\n';
    }
    return 0;
}