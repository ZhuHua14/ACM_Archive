#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXLOG = 25;
int n,m,a[MAXN],f[MAXN][MAXLOG];
/*f[i][j] 为以i为首，长度为pow(2,j - 1) + 1的子段中的最大值*/
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
        f[i][0] = a[i];
    }
    for(int j = 1; j <= MAXLOG; j++){
        for(int i = 1; i + (1 << j) - 1 <= n; i++){
            f[i][j] = max(f[i][j - 1],f[i + (1 << (j - 1))/*i + pow(2,j - 1)*/][j - 1]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    init();
    int nowl,nowr;
    for(int i = 1; i <= m; i++){
        cin >> nowl >> nowr;
        int nowmid = lb[nowr - nowl + 1];
        cout << max(f[nowl][nowmid],f[nowr - (1 << nowmid) + 1][nowmid]) << '\n';
    }
    return 0;
}