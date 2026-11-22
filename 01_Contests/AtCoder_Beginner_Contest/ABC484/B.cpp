// B - Nineball
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x, ans = 1e9;
    bool flag = 0;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> x;
        ans = min(ans, x);
        if (x == 9)
            flag = 1;
    }
    if (!flag) {
        cout << -1;
    } else
        cout << ans;
    return 0;
}