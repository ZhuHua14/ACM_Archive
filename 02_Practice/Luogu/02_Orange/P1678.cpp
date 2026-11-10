// P1678 烦恼的高考志愿
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

ll n,m,a[MAXN],b[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for(int i = 1; i <= m; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    sort(a + 1,a + 1 + m);
    ll ans = 0,tmp = 0;
    for(int i = 1; i <= n; i++){
        tmp = lower_bound(a + 1,a + m + 1,b[i]) - a;
        if(tmp <= 1){
            ans += abs(b[i] - a[1]);
            continue;
        }
        ans += min(abs(b[i] - a[tmp]),abs(b[i] - a[tmp - 1]));
    }
    cout << ans;
    return 0;
}