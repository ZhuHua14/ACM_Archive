#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 15;
ll cube[MAXN][MAXN];
ll n,f[MAXN][MAXN][MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int x,y,val;
    while(cin >> x >> y >> val){
        if(x == 0 && y == 0 && val == 0){
            break;
        }
        cube[x][y] = val;
    }
    for(int x1 = 1; x1 <= n; x1++){
        for(int x2 = 1; x2 <= n; x2++){
            for(int y1 = 1; y1 <= n; y1++){
                for(int y2 = 1; y2 <= n; y2++){
                    f[x1][y1][x2][y2] = max(max(f[x1 - 1][y1][x2 - 1][y2],f[x1][y1 - 1][x2][y2 - 1]),max(f[x1 - 1][y1][x2][y2 - 1],f[x1][y1 - 1][x2 - 1][y2])) + cube[x1][y1] + ((x1 == x2 && y1 == y2)? 0:cube[x2][y2]);
                }
            }
        }
    }
    cout << f[n][n][n][n] << endl;
    return 0;
}