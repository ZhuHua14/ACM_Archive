//P14635 [NOIP2025] 糖果店
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

struct Candy{
    ll x, y;
};
Candy candy[MAXN];
bool cmp(Candy a,Candy b){
    return a.x < b.x;
}

ll n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    candy[0].x = candy[0].y = 0;
    for(int i = 1; i <= n; i++){
        cin >> candy[i].x >> candy[i].y;
    }
    sort(candy + 1, candy + 1 + n, cmp);
    
    ll minsum = LLONG_MAX;

    for(int i = 1; i <= n; i++){
        minsum = min(minsum, candy[i].x + candy[i].y);
    }

    ll presum = 0, tmp = 0, ans = 0;
    for(int i = 0; i <= n; i++){
        //cerr << i << ' ';
        tmp = 0;
        presum += candy[i].x;
        //cerr << presum << ' ';
        if(presum > m) break;
        tmp += i;
        //cerr << tmp << ' ';
        tmp += ((m - presum) / minsum) * 2;
        //cerr << tmp << '\n';
        ans = max(ans, tmp);
    }
    cout << ans;
    return 0;
}