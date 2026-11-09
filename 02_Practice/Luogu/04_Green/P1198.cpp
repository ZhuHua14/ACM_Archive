#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5 + 5;
const int MAXLOG = 25;
int m,d,a[MAXN],lb[MAXN],preans,len,f[MAXN][MAXLOG];
void init(){
    lb[1] = 0;
    lb[2] = 1;
    for(int i = 3; i <= MAXN; i++){
        lb[i] = lb[i / 2] + 1;
    }
}

void balence(){
    f[len][0] = a[len];
    for(int i = 1; len - (1 << i) + 1 > 0; i++){
        f[len][i] = max(f[len][i - 1],f[len - (1 << (i - 1))][i - 1]);
    }
}

int find(int nowlen){
    int mid = lb[nowlen];
    return preans = max(f[len][mid],f[(len - nowlen + 1) + (1 << mid) - 1][mid]);
}

void insert(int n,const int mod){
    a[++len] = (n % mod + preans % mod) % mod;
    balence();
}

signed main(){
    cin >> m >> d;
    char opt;
    int nown;
    init();
    while(m--){
        cin >> opt >> nown;
        if(opt == 'A'){
            insert(nown,d);
        }
        else if(opt == 'Q'){
            cout << find(nown) << '\n';
        }
    }
    return 0;
}