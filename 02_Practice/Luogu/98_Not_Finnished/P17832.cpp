#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXM = 5e5 + 5;
const int MAXN = 505;
//slu : 预处理出各线路之间换乘的步行时长

struct Stations{
    /*站点编号 i号线站台到该站站厅的时间*/
    int name, t;
};
struct Line{
    vector<Stations> stations;
};

Line line[MAXN];
int t1[MAXN][MAXN];

struct Lines{
    /*线路编号 i号线站台到该站站厅的时间*/
    int name, t;
};
struct Station{
    int w;
    vector<Lines> lines;
};

Station station[MAXN]; 

int c, m, n, d, q;

void init(){
    memset(t1,0x7f,sizeof(t1));
    for (int i = 1; i <= n; i++){
        for (auto s : line[i].stations){
            for (auto l : station[s.name].lines){

            }
        }
    }


}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> station[i].w;
    }
    int k;
    pair<int, int> tmp;
    Stations st;
    for(int i = 1; i <= n; i++){
        cin >> k;
        for(int j = 1; j <= k; j++){
            cin >> st.name >> st.t;
            line[i].stations.push_back(st);
            station[st.name].lines.push_back({i, st.t});
        }
    }

    init();

    int x, y;
    while(q--){
        cin >> x >> y;

    }

    return 0;
}