#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e3 + 5;
const int MAXM = 205;

int n,m,K,f[2][MAXM][MAXM],sum[2][MAXM][MAXM];

char a[MAXN],b[MAXN];
//f[i][j][k] = f[i - 1][j][k] (a[i] != b[j]);
//f[i][j][k] = f[i - 1][j][k] + sigma(len = 0,t)

signed main(){
    //freopen("out_my.out","w",stdout);
    scanf("%d%d%d",&n,&m,&K);
    scanf("%s%s",a + 1,b + 1);
    f[0][0][0] = 1;
    for(int i = 1; i <= n; i++){
        f[i % 2][0][0] = 1;
        for(int j = 1; j <= m ;j++){
            for(int k = 0; k <= K; k++){
                f[i % 2][j][k] = f[(i - 1) % 2][j][k] % MOD;
                if(a[i] != b[j]){
                    sum[i % 2][j][k] = 0;
                }
                else{
                    sum[i % 2][j][k] += sum[(i - 1) % 2][j - 1][k] + f[(i - 1) % 2][j - 1][k - 1];
                }
                sum[i % 2][j][k] %= MOD;
                /*int len = 1;
                while(a[i - len] == b[j - len] && j - len > 0 && i - len > 0){
                    f[i][j][k] += f[i - len][j - len][k - 1];
                    f[i][j][k] %= MOD;
                    len++;
                }*/
                f[i % 2][j][k] += sum[i % 2][j][k];
                f[i % 2][j][k] %= MOD;
            }
        }
        memset(sum[(i - 1) % 2],0,sizeof(sum[(i - 1) % 2]));
    }
    cout << f[n % 2][m][K];
    return 0;
}