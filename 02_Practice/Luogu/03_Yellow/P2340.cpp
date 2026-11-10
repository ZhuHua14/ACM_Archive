// P2340 [USACO03FALL] Cow Exhibition G
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 405;
const int MAXS = 8e5 + 999;
const int DELTA = 4e5;

struct Node{
    ll s,f;
};

Node node[MAXN];

ll n,dp[2][MAXS];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> node[i].s >> node[i].f;
    }
    memset(dp,-0x3f,sizeof(dp));
    dp[0][DELTA] = 0;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 8e5; j++){
            if(j - node[i].s >= 0){
                dp[i % 2][j] = max(dp[(i - 1) % 2][j],dp[(i - 1) % 2][j - node[i].s] + node[i].f);
            }
            else dp[i % 2][j] = dp[(i - 1) % 2][j];
        }
    }
    for(int i = DELTA; i < 8e5; i++){
        if(dp[n % 2][i] >= 0) ans = max(ans,i - DELTA + dp[n % 2][i]);
    }
    cout << ans << endl;
    return 0;
}
