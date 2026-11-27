// C - Bank Accounts
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<string, int> acc;
int q, cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> q;
    string name;
    while (q--) {
        cin >> name;
        if (acc.find(name) == acc.end())
            acc.insert(make_pair(name, ++cnt));
        cout << acc[name] << '\n';
    }
    return 0;
}