// D - Move One Card Left
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;

int n, bot[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    int x, tmp = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (tmp != x)
            ans += i - bot[x] - 1;
        // cerr << x << ' ' << i - bot[x] - 1 << ' ' << bot[x] << ' ' << ans
        //      << '\n';
        bot[x]++;
        tmp = x;
    }
    cout << ans + 1;
    return 0;
}