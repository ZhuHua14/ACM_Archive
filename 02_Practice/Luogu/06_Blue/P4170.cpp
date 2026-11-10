// P4170 [CQOI2007] 涂色
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 55;

char a[MAXN];
int f[MAXN][MAXN],n;

int main(){
    cin.getline(a + 1, MAXN);
    n = strlen(a + 1);
    memset(f,0x3f,sizeof(f));
    for(int i = 1; i <= n; i++){
        f[i][i] = 1;
    }
    for(int len = 2; len <= n; len++){
        for(int l = 1; l + len - 1 <= n; l++){
            int r = l + len - 1;
            if(a[l] == a[r]){
                f[l][r] = min(f[l - 1][r],f[l][r - 1]);
            }
            else{
                for(int k = l; k <= r; k++){
                    f[l][r] = min(f[l][r],f[l][k] + f[k + 1][r]);
                }
            }

        }
    }
    cout << f[1][n] << endl;
    return 0; 
}