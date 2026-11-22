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
    int pa = 1e9, pb = 1e9, pc = 1e9;
    int ea = 0, eb = 0, ec = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            pa = min(pa, i);
            ea = max(ea, i);
        }
        if (s[i] == 'B') {
            pb = min(pb, i);
            eb = max(eb, i);
        }
        if (s[i] == 'C') {
            pc = min(pc, i);
            ec = max(ec, i);
        }
    }
    cerr << pa << ' ' << pb << ' ' << pc << '\n';
    cerr << ea << ' ' << eb << ' ' << ec << '\n';

    int la = pa, lb = pb, lc = pc, minl;
    int l = max(pa, max(pb, pc)) + 1;
    int r = min(ea, min(eb, ec)) - 1;
    ll ans = 0;
    for (int i = l; i <= r; i++) {
        if (s[i] == 'A') {
            la = i;
        }
        if (s[i] == 'B') {
            lb = i;
        }
        if (s[i] == 'C') {
            lc = i;
        }
        minl = min(la, min(lb, lc));
        cerr << i << ' ' << minl << ' ' << minl - l + 1 << '\n';
        if (minl - l + 1 > 0) {
            ans += minl - l + 1;
            cerr << "111\n";
        }
    }
    cout << ans;
    return 0;
}