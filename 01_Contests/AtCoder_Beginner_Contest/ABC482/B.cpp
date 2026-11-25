// B - Blank Bingo
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 8;

string s[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 1; i <= 5; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    int ans = 1e9, tmp1 = 0, tmp2 = 0;
    for (int i = 1; i <= 5; i++) {
        tmp1 = 0;
        tmp2 = 0;
        for (int j = 1; j <= 5; j++) {
            if (s[i][j] == 'o')
                tmp1++;
            if (s[j][i] == 'o')
                tmp2++;
        }
        ans = min(min(5 - tmp1, 5 - tmp2), ans);
    }
    tmp1 = 0;
    tmp2 = 0;
    for (int i = 1; i <= 5; i++) {
        if (s[i][i] == 'o')
            tmp1++;
        if (s[i][5 - i] == 'o')
            tmp2++;
        // cerr << i << ' ' << s[i][i] << ' ' << tmp << '\n';
        ans = min(min(5 - tmp1, 5 - tmp2), ans);
    }
    cout << ans;
    return 0;
}