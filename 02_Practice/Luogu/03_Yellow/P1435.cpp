#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e3 + 5;

char s[MAXN];
int n,f[MAXN][MAXN];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin.getline(s + 1, 1e3 + 4);
    n = strlen(s + 1);
    for(int len = 1; len <= n; len++){
        for(int l = 1; l + len - 1 <= n; l++){
            int r = l + len - 1;
            if(l == r) f[l][r] = 0;
            else if(s[l] == s[r]) f[l][r] = f[l + 1][r - 1];
            else if(s[l] != s[r]) f[l][r] = min(f[l + 1][r] + 1,f[l][r - 1] + 1);
        }
    }
    cout << f[1][n] << endl;
    return 0;
}