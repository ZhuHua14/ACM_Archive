#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e3 + 5;

int n,m;
bool cb[MAXN][MAXN];
struct Node{
    int l,r,u;
};
Node f[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    char ch;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> ch;
            cb[i][j] = (ch == 'R')? 0:1;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            f[i][j].l = (cb[i][j] && cb[i][j - 1])? f[i][j - 1].l:j;
            f[i][j].u = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= 1; j--){
            f[i][j].r = (cb[i][j] && cb[i][j + 1])? f[i][j + 1].r:j;
        }
    }
    int ans = 0,d = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!cb[i][j]) continue;
            if(cb[i - 1][j] && cb[i][j]){
                f[i][j].l = max(f[i - 1][j].l,f[i][j].l);
                f[i][j].r = min(f[i - 1][j].r,f[i][j].r);
                f[i][j].u = f[i - 1][j].u + 1;
            }
            d = f[i][j].r - f[i][j].l + 1;
            ans = max(ans,f[i][j].u * d);
        }
    }
    cout << ans * 3 << '\n';
    return 0;
}