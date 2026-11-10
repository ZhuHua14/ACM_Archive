// P1216 [IOI 1994 / USACO1.5] 数字三角形 Number Triangles
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
int tri[MAXN][MAXN],f[MAXN][MAXN],r;
int main(){
    cin >> r;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= i; j++){
            cin >> tri[i][j];
        }
    }
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= i; j++){
            f[i][j] = tri[i][j] + max(f[i - 1][j - 1],f[i - 1][j]);  
        }
    }
    int ans = 0;
    for(int i = 1; i <= r; i++){
        ans = max(f[r][i],ans);
    }
    cout << ans;
    return 0;
}