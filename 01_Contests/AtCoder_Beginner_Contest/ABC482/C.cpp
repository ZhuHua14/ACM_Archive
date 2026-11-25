// C - Band Count
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3e5 + 5;

struct Ques {
    int op, l, r;
};
Ques ask[MAXN];

vector<int> v[2];
pair<int, int> points[MAXN];
int h, w, n, q;

vector<int> rows, cols;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> h >> w >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> points[i].first >> points[i].second;
        v[0].push_back(points[i].first);
        v[1].push_back(points[i].second);
    }
    int op;
    Ques tmp;
    for (int i = 1; i <= q; i++) {
        cin >> tmp.op >> tmp.l >> tmp.r;
        tmp.op--;
        ask[i] = tmp;
        v[tmp.op].push_back(tmp.l);
        v[tmp.op].push_back(tmp.r);
    }
    /**/
    vector<int>::iterator it[2];
    sort(v[0].begin(), v[0].end());
    it[0] = unique(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    it[1] = unique(v[1].begin(), v[1].end());
    for (int i = 1; i <= n; i++) {
        points[i].first = lower_bound(v[0].begin(), it[0], points[i].first) -
                          v[0].begin() + 1;
        points[i].second = lower_bound(v[1].begin(), it[1], points[i].second) -
                           v[1].begin() + 1;
    }
    for (int i = 1; i <= q; i++) {
        op = ask[i].op;
        ask[i].l =
            lower_bound(v[op].begin(), it[op], ask[i].l) - v[op].begin() + 1;
        ask[i].r =
            lower_bound(v[op].begin(), it[op], ask[i].r) - v[op].begin() + 1;
    }
    /* */
    rows.resize(it[0] - v[0].begin() + 5, 0);
    cols.resize(it[1] - v[1].begin() + 5, 0);
    for (int i = 1; i <= n; i++) {
        rows[points[i].first]++;
        cols[points[i].second]++;
    }
    for (int i = 1; i < rows.size(); i++) {
        rows[i] += rows[i - 1];
    }
    for (int i = 1; i < cols.size(); i++) {
        cols[i] += cols[i - 1];
    }
    for (int i = 1; i <= q; i++) {
        op = ask[i].op;
        if (op == 0) {
            cout << rows[ask[i].r] - rows[ask[i].l - 1] << '\n';
        } else {
            cout << cols[ask[i].r] - cols[ask[i].l - 1] << '\n';
        }
    }
    return 0;
}