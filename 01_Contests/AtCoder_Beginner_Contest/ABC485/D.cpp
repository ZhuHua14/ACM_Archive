// D - ABC|ABC|ABC
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string s;

/*
max(pa,pb,pc) min(la,lb,lc) min(ea,eb,ec)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> s;
    int p[3] = {1 << 30, 1 << 30, 1 << 30}, e[3] = {0, 0, 0}, la[3];
    for (int i = 0; i < s.size(); i++) {
        p[s[i] - 'A'] = min(p[s[i] - 'A'], i);
        e[s[i] - 'A'] = max(e[s[i] - 'A'], i);
    }
    // cerr << pa << ' ' << pb << ' ' << pc << '\n';
    // cerr << ea << ' ' << eb << ' ' << ec << '\n';
    for (int i = 0; i < 3; i++) {
        la[i] = p[i];
    }
    int minl = 1e9;
    int l = max(p[0], max(p[1], p[2])) + 1;
    int r = min(e[0], min(e[1], e[2])) - 1;
    ll ans = 0;
    for (int i = l; i <= r; i++) {
        la[s[i] - 'A'] = i;
        minl = min(la[0], min(la[1], la[2]));
        // cerr << i << ' ' << minl << ' ' << minl - l + 1 << '\n';
        if (minl - l + 1 > 0) {
            ans += minl - l + 1;
            cerr << "111\n";
        }
    }
    cout << ans;
    return 0;
}