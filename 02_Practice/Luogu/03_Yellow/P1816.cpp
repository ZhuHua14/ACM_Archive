#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXLOG = 21;
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
    for(int i = 1; i <= m; i++){
        f[i][0] = a[i];
    }
    for(int j = 1; j <= MAXLOG; j++){
        for(int i = 1; i + (1 << j) - 1 <= m; i++){
            f[i][j] = min(f[i][j - 1],f[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        //cout << '1';
        cin >> a[i];
    }
    init();
    int l,r;
    for(int i = 1; i <= n; i++){
        cin >> l >> r;
        int mid = lb[r - l + 1];
        cout << min(f[l][mid],f[r - (1 << mid) + 1][mid]) << ' ';
    }
    return 0;
}