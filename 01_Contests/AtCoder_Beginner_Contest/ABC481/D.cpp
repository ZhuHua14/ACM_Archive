// D - Autopilot
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
const int INF = 0x7f7f7f7f;

struct Edge {
    int u, v, w = 1;
};

bool cmp(Edge a, Edge b) {
    return a.v < b.v;
}

vector<Edge> edge[MAXN];
int n, m, s, t;

struct Node {
    int u, dis;

    bool operator>(const Node oth) const {
        return dis > oth.dis;
    }
};

void dij() {
    int dis[MAXN] = {};
    bool vis[MAXN] = {};
    memset(dis, 0x7f, sizeof(dis));
    dis[s] = 0;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({s, dis[s]});
    while (!pq.empty()) {
        int u = pq.top().u;
        // cerr << u << ' ' << pq.top().dis << '\n';
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto e : edge[u]) {
            if (dis[e.u] + e.w < dis[e.v]) {
                dis[e.v] = dis[e.u] + e.w;
                pq.push({e.v, dis[e.v]});
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cerr << (dis[t] == INF ? -1 : dis[t]) << ' ';
    // }
    cout << (dis[t] == INF ? -1 : dis[t]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> s >> t;
    Edge tmp;
    for (int i = 1; i <= m; i++) {
        cin >> tmp.u >> tmp.v;
        edge[tmp.u].push_back(tmp);
    }
    for (int i = 1; i <= n; i++) {
        if (edge[i].empty())
            continue;
        sort(edge[i].begin(), edge[i].end(), cmp);
        edge[i][0].w = 0;
    }
    dij();
    return 0;
}