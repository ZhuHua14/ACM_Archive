#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int MAXLOG = 25;
int n,m,a[MAXN];
int f[MAXN][MAXLOG];
int lb[MAXN];
void getLog(){
    lb[1] = 0;
    lb[2] = 1;
    for(int i = 3; i < MAXN; i++){
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
            f[i][j] = min(f[i][j - 1],f[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    init();
    for(int l = 1; l <= n - m + 1; l++){
        int r = l + m - 1;
        cout << min(f[l][lb[m]],f[r - (1 << lb[m]) + 1][lb[m]]) << '\n';
    }
    return 0;
}