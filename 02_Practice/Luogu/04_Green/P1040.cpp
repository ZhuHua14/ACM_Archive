// P1040 [NOIP 2003 提高组] 加分二叉树
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 35;

ll n,f[MAXN][MAXN],a[MAXN],root[MAXN][MAXN];

void print(int l,int r){
    if(root[l][r] == 0 || l > r) return;
    cout << root[l][r] << ' ';
    print(l,root[l][r] - 1);
    print(root[l][r] + 1,r); 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int len = 1; len <= n; len++){
        for(int l = 1; l + len - 1 <= n; l++){
            int r = l + len - 1;
            f[l][r] = f[l + 1][r] + a[l];
            root[l][r] = l;
            for(int k = l; k <= r; k++){
                if(f[l][r] < f[l][k - 1] * f[k + 1][r] + a[k]){
                    f[l][r] = f[l][k - 1] * f[k + 1][r] + a[k];
                    root[l][r] = k;
                }
            }
        }
    }

    cout << f[1][n] << endl;
    print(1,n);
    return 0;
}