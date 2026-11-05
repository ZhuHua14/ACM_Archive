#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int MAXM = 1e4 + 5;
int n,m,f[2][MAXM],a[MAXN];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    f[0][0] = 1;
    for(int i = 1; i <= n; i++){
        f[i % 2][0] = 1;
        for(int j = 1; j <= m; j++){
            if(j >= a[i]){
                f[i % 2][j] = f[(i - 1) % 2][j] + f[(i - 1) % 2][j - a[i]];
            }
            else{
                f[i % 2][j] = f[(i - 1) % 2][j];
            }
        }
    }
    cout << f[n % 2][m];
    return 0;
}