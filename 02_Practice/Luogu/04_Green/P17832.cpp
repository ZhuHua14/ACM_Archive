//P17832 [CSP-S 2026] 地铁 / subway
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXM = 5e5 + 5;
const int MAXN = 505;
const ll INF = 0x7f7f7f7f7f7f7f7f;
//slu : 预处理出各线路之间换乘的步行时长

struct Stations{
    /*站点编号 i号线站台到该站站厅的时间*/
    ll name, t;
};
struct Line{
    vector<Stations> stations;
};

Line line[MAXN];
ll t1[MAXN][MAXN];

struct Lines{
    /*线路编号 该号线站台到i站站厅的时间*/
    ll name, t;
};
struct Station{
    ll w;
    vector<Lines> lines;
};

Station station[MAXM]; 

ll c, m, n, d, q;

void print_t1(){
    // for(ll i = 1; i <= n; i++){
    //     for(ll j = 1; j <= n; j++) cerr << (t1[i][j] == INF? -1:t1[i][j]) << ' ';
    //     cerr << '\n';
    // }
}

void init(){
    memset(t1,0x7f,sizeof(t1));
    for(int i = 1; i <= n; i++){
        t1[i][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (auto s : line[i].stations) {
            for (auto l : station[s.name].lines) {
                t1[i][l.name] = t1[l.name][i] = min(t1[i][l.name], s.t + l.t);
            }
        }
    }

    print_t1();
    cerr << '\n';
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(t1[i][k] == INF && t1[i][k] == INF) continue;
                t1[i][j] = min(t1[i][j], t1[i][k] + t1[k][j]);
            }
        }
    }
}




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> c >> n >> m >> d >> q;
    for(ll i = 1; i <= m; i++){
        cin >> station[i].w;
    }
    ll k;
    Stations st;
    for(ll i = 1; i <= n; i++){
        cin >> k;
        for(ll j = 1; j <= k; j++){
            cin >> st.name >> st.t;
            line[i].stations.push_back(st);
            station[st.name].lines.push_back({i, st.t});
        }
    }

    init();

    print_t1();

    ll x, y;
    ll ans = 0, mt = 0x7f7f7f7f7f7f7f7f;
    while(q--){
        ans = 0,mt = 0x7f7f7f7f7f7f7f7f;
        cin >> x >> y;
        ans = station[x].w + station[y].w;
        for(auto l1 : station[x].lines){
            for(auto l2 : station[y].lines){
                mt = min(mt, l1.t + t1[l1.name][l2.name] + l2.t);
            }
        }
        ans += mt;
        cout << ans <<  '\n';
    }

    return 0;
}