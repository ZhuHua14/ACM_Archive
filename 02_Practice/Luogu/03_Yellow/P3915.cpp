//P3915 树的分解
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
/*要想保证尽量联通，必须是一个子树一个子树拼
  而且一旦拼上子树, 其他子树就只能单走
*/

struct Edge{
    int f, t;
};
vector<Edge> edge[MAXN];

int sz[MAXN];
int T, n, k;

bool dfs1(int u,int fa){
    ////cerr << u << ' ' << fa << '\n';
    sz[u] = 1;
    bool res = 1;
    for(auto e : edge[u]){      
        if(e.t == fa) continue;
        res = dfs1(e.t,e.f);
        if(!res) return 0;
        if(sz[e.t] == k) continue;
        sz[u] += sz[e.t];
        if(sz[u] > k) return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    Edge tmp;
    bool ret = 0;
    while(T--){
        cin >> n >> k;
        memset(sz, 0, sizeof(sz));
        for(int i = 1; i <= n; i++){
            edge[i].clear();
        }
        for(int i = 1; i <= n - 1; i++){
            cin >> tmp.f >> tmp.t;
            edge[tmp.f].push_back(tmp);
            edge[tmp.t].push_back({tmp.t,tmp.f});
        }
        if(n % k != 0){
            cout << "NO\n";
            continue;
        }
        ret = dfs1(1,-1); 
        cout << (ret? "YES\n":"NO\n");
        //cerr << '\n';
    }
    return 0;
}