// B - Faucets and Drains
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 105;

int n, m;
string s[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    int posr = 0, posc = -1;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (char ch : s[i]) {
            if (ch == 'x') {
                posr = posr == 0 || posr == i ? i : -1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[j][i] == 'x') {
                posc = posc == -1 || posc == i + 1 ? i + 1 : -1;
            }
        }
    }
    if (posc == -1)
        cout << "Faucet " << posr;
    else
        cout << "Drain " << posc;
    return 0;
}