// P1140 相似基因
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 105;
const int INF = 0x3f3f3f3f3f3f3f3f;
//A = 1, C = 2, G = 3; T = 4; EMPTY = 0
int sim[5][5] = {{-INF,-3,-4,-2,-1},
                 {-3,5,-1,-2,-1},
                 {-4,-1,5,-3,-2},
                 {-2,-2,-3,5,-2},
                 {-1,-1,-2,-2,5}
                };

int a_n,b_n,a[MAXN],b[MAXN],f[MAXN][MAXN];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a_n;
    char op;
    for(int i = 1; i <= a_n; i++){
        cin >> op;
        if(op == 'A') a[i] = 1;
        else if(op == 'C') a[i] = 2;
        else if(op == 'G') a[i] = 3;
        else if(op == 'T') a[i] = 4;
    }
    /*for(int i = 1; i <= a_n; i++){
        cout << a[i];
    }
    cout << '\n';*/
    cin >> b_n;
    for(int i = 1; i <= b_n; i++){
        cin >> op;
        if(op == 'A') b[i] = 1;
        else if(op == 'C') b[i] = 2;
        else if(op == 'G') b[i] = 3;
        else if(op == 'T') b[i] = 4;
    }
    /*for(int i = 1; i <= b_n; i++){
        cout << b[i];
    }
    cout << '\n';*/
    for(int i = 1; i <= a_n; i++){
        f[i][0] = f[i - 1][0] + sim[a[i]][0];
    }
    for(int i = 1; i <= b_n; i++){
        f[0][i] = f[0][i - 1] + sim[b[i]][0];
    }
    for(int i = 1; i <= a_n; i++){
        for(int j = 1; j <= b_n; j++){
            f[i][j] = max(f[i - 1][j] + sim[a[i]][0],max(f[i - 1][j - 1] + sim[a[i]][b[j]],f[i][j - 1] + sim[0][b[j]]));
        }
    }
    cout << f[a_n][b_n];
    return 0;
}