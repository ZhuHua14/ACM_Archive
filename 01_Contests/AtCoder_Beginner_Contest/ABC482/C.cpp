// C - Band Count
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3e5 + 5;
int h, w, n, q;

int rows[MAXN], cols[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> h >> w >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> rows[i] >> cols[i];
    }
    sort(rows + 1, rows + 1 + n);
    sort(cols + 1, cols + 1 + n);
    int op, l, r;
    while (q--) {
        cin >> op >> l >> r;
        const auto& v = ((op == 1) ? rows : cols);
        cout << upper_bound(v + 1, v + 1 + n, r) -
                    lower_bound(v + 1, v + 1 + n, l)
             << '\n';
    }
    return 0;
}