// P1855 榨取kkksc03
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int MAXM = 205;
const int MAXT = 205;

struct Node{
    int t,m;
};

Node node[MAXN];

int f[MAXN][MAXM][MAXT],M,n,T;

int main(){
    cin >> n >> M >> T;
    for(int i = 1; i <= n; i++){
        cin >> node[i].m >> node[i].t;
    }
    for(int i = 1; i <= n; i++){
        for(int t = 0; t <= T; t++){
            for(int m = 0; m <= M; m++){
                if(t >= node[i].t && m >= node[i].m) f[i][t][m] = max(f[i - 1][t][m],f[i - 1][t - node[i].t][m - node[i].m] + 1);
                else f[i][t][m] = f[i - 1][t][m];
            }
        }
    }
    cout << f[n][T][M];
    return 0;
}