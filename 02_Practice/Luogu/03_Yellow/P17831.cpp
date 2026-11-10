// P17831 [CSP-S 2026] 能量水晶
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAXN = 5e5 + 5;

ll a[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    ll l = 1, r = 1, cost = 0, ans = 0;
    while(r <= n){
        //cerr << l << " " << r;
        cost += (a[r] - a[r - 1]) * (r - l);
        //cerr << " cost = " << cost << '\n';
        while(l <= r && cost > m){
            //cerr << l << ' ';
            cost -= a[r] - a[l];
            //cerr << " cost = "<< cost << '\n';
            l++;
        }
        ans = max(ans, r - l + 1);
        r++;
        //cerr << "ans = " << ans << '\n';
    } 
    cout << ans;
    return 0;
}