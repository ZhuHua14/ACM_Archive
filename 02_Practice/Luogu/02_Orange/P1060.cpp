// P1060 [NOIP 2006 普及组] 开心的金明
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 30;
const int MAXV = 3e4 + 5;
struct Node{
    int val,imp;
};
Node node[MAXN];

int n,m,f[MAXN][MAXV];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> node[i].val >> node[i].imp;
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(j < node[i].val){
                f[i][j] = f[i - 1][j];
            }
            else{
                f[i][j] = max(f[i - 1][j],f[i - 1][j - node[i].val] + (node[i].val * node[i].imp));
            }
        }
    }
    cout << f[m][n];
    return 0;
}