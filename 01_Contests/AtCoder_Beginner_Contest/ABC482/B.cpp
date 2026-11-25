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
    int ans = 1e9, tmp = 0;
    for (int i = 1; i <= 5; i++) {
        tmp = 0;
        for (int j = 1; j <= 5; j++) {
            if (s[i][j] == 'o')
                tmp++;
        }
        ans = min(5 - tmp, ans);
    }
    for (int i = 1; i <= 5; i++) {
        tmp = 0;
        for (int j = 1; j <= 5; j++) {
            if (s[j][i] == 'o')
                tmp++;
        }
        ans = min(5 - tmp, ans);
    }
    tmp = 0;
    for (int i = 1; i <= 5; i++) {
        if (s[i][i] == 'o')
            tmp++;
        // cerr << i << ' ' << s[i][i] << ' ' << tmp << '\n';
        ans = min(5 - tmp, ans);
    }
    tmp = 0;
    for (int i = 1; i <= 5; i++) {
        if (s[i][5 - i + 1] == 'o')
            tmp++;
        ans = min(5 - tmp, ans);
    }
    cout << ans;
    return 0;
}