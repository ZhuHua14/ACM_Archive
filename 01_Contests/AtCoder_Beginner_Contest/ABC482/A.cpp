// A - Nigiri
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int ans = 0;
    for (auto ch : s) {
        if (ch == 'o')
            ans++;
    }
    cout << ((ans % 2 == 0) ? "even" : "odd");
    return 0;
}