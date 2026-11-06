#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e4 + 5;
struct Range{
    int l,r,len;
};
Range range[MAXN];
int n,f[MAXN][2];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> range[i].l >> range[i].r;
        range[i].len = range[i].r - range[i].l;
    }
    f[1][0] = range[1].len + range[1].r - 1;
    f[1][1] = range[1].len + range[1].l - 1;
    for(int i = 2; i <= n; i++){
        f[i][0] = min(f[i - 1][0] + abs(range[i - 1].l - range[i].r),f[i - 1][1] + abs(range[i - 1].r - range[i].r)) + range[i].len + 1;
        f[i][1] = min(f[i - 1][0] + abs(range[i - 1].l - range[i].l),f[i - 1][1] + abs(range[i - 1].r - range[i].l)) + range[i].len + 1;
    }
    cout << min(f[n][0] + (n - range[n].l),f[n][1] + (n - range[n].r)) << endl;
    return 0;
}