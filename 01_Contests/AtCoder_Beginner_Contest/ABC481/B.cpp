// B - Polyline
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int pos, prepos, l, r, ans = 0;
    for (int i = 1; i <= n; i++) {
        prepos = pos;
        cin >> pos;
        l = min(pos, prepos);
        r = max(pos, prepos);
        if (i == 1) {
            if (pos == k)
                ans++;
            continue;
        }
        if (pos == k || l < k && r > k)
            ans++;
    }
    cout << ans;
    return 0;
}