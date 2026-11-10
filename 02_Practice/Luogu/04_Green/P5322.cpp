// P5322 [BJOI2019] 排兵布阵
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 105;
const int MAXM = 2e4 + 5;
vector<int> llist[MAXN];
//f[i][j] -> 在前i个城堡花了j个士兵时可以获得的最大得分

//f[i][j] = max(f[i][j],max(up:s,down:k = 0)(f[i - 1][j - 2 * node[i][k].val] + sum(up:k,down:l = 0)(node[i][l].score)));
int f[MAXN][MAXM],s,n,m;
signed main(){
    cin >> s >> n >> m;
    int nowval;
    for(int i = 1; i <= s; i++){
        for(int j = 1; j <= n; j++){
            cin >> nowval;
            llist[j].push_back(nowval);
        }
    }
    for(int i = 1; i <= n; i++){
        sort(llist[i].begin(),llist[i].end());
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            for(int k = 0; k < llist[i].size(); k++){
                f[i][j] = max(f[i][j],f[i - 1][j]);
                if(j >= llist[i][k] * 2 + 1){
                    f[i][j] = max(f[i][j],f[i - 1][j - 2 * llist[i][k] - 1] + (k + 1) * i);
                }
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}