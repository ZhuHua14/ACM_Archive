// C - Move One Card
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;

int n, a[MAXN], b[MAXN];

bool chk1(int l, int r) {
    if (a[r] != b[l])
        return 0;
    for (int i = l; i < r; i++) {
        if (a[i] != b[i + 1])
            return 0;
    }
    return 1;
}

bool chk2(int l, int r) {
    if (a[l] != b[r])
        return 0;
    for (int i = l; i < r; i++) {
        if (a[i + 1] != b[i])
            return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int posmin = 1e9, posmax = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
            posmin = min(posmin, i);
            posmax = max(posmax, i);
        }
    }
    // cerr << posmin << ' ' << posmax;
    if (posmin == 1e9 && posmax == 0) {
        cout << "Yes";
    } else if (a[posmin] != b[posmax] && a[posmax] != b[posmin]) {
        cout << "No";
    } else if (chk1(posmin, posmax) || chk2(posmin, posmax)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}