// C - Different Neighbor
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3e5 + 5;

struct Node {
    int len = 0, c;
};

Node node[MAXN];
int n, cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    int col;
    for (int i = 1; i <= n; i++) {
        cin >> col;
        if (col != node[cnt].c) {
            node[++cnt].c = col;
        }
        node[cnt].len++;
    }
    int prepos = 0, nxtpos = 0, posn = 0;
    for (int i = 1; i <= n; i++) {
        if (nxtpos < i) {
            prepos = nxtpos;
            nxtpos += node[++posn].len;
        }
        cerr << prepos << ' ' << nxtpos << '\n';
        if (prepos == 0)
            cout << nxtpos + 1 - i << ' ';
        else if (nxtpos == n)
            cout << i - prepos << ' ';
        else
            cout << min(nxtpos + 1 - i, i - prepos) << ' ';
    }
    return 0;
}