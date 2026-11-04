#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e3 + 5;
const int MAXS = 1e4 + 5;
const int DELTA = 5e3;
struct Node{
    ll u,d;
    Node(ll _u,ll _d): u(_u),d(_d) {}
    Node() {}
};
Node node[MAXN];
ll f[2][MAXS],n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> node[i].u >> node[i].d;
    }
    memset(f,0x3f,sizeof(f));
    f[0][DELTA] = 0;
    ll ans = 0,mins = 0x3f3f3f3f3f3f3f3f;
    for(int i = 1; i <= n; i++){
        memset(f[i % 2],0x3f,sizeof(f[i % 2]));
        for(int j = 0; j <= MAXS; j++){
            if(j + (node[i].u - node[i].d) >= 0) f[i % 2][j] = min(f[i % 2][j],f[(i - 1) % 2][j + (node[i].u - node[i].d)]);
            if(j + (node[i].d - node[i].u) >= 0) f[i % 2][j] = min(f[i % 2][j],f[(i - 1) % 2][j + (node[i].d - node[i].u)] + 1);
        }
    }
    for(int j = 1; j <= MAXS; j++){
        if(f[n % 2][j] != 0x3f3f3f3f3f3f3f3f && mins > abs(j - DELTA)){
            mins = abs(j - DELTA);
            ans = f[n % 2][j];
        }
    }
    cout << ans << endl;
    return 0;
}