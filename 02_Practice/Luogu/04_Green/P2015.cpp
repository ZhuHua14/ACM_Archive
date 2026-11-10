// P2015 二叉苹果树
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 105;
struct Edge{
    ll from,to,val;

    Edge(ll _from,ll _to,ll _val){
        from = _from;
        to = _to;
        val = _val;
    }

    Edge(){}
};
//f[u][i] = ((u,s) belongs to Edge) (0 >= j >= i) max(f[u][i - j - 1] + f[s][j] + edge[u][j].val);
vector<Edge> edge[MAXN];
ll n,q,f[MAXN][MAXN],sz[MAXN];

void init(int u,int fa){
    sz[u]++;
    for(int i = 0; i < edge[u].size(); i++){
        if(edge[u][i].to != fa){
            init(edge[u][i].to,u);
        }
    }
    for(int i = 0; i < edge[u].size(); i++){
        if(edge[u][i].to != fa){
            sz[u] += sz[edge[u][i].to];
        }
    }
}

void dfs(int u,int fa){
    ll cnt = 0;
    pair<ll,ll> s[3];/*fir = cnt,sec = v*/
    for(int i = 0; i < edge[u].size(); i++){
        if(edge[u][i].to != fa){
            dfs(edge[u][i].to,u);
            s[++cnt] = make_pair(edge[u][i].to,edge[u][i].val);
        }
    }
    //cout << s[1].first << ' ' << s[1].second << ' ' << s[2].first << ' ' << s[2].second << ' ';
    for(int i = 1; i <= min(sz[u],q); i++){
        //cout << i << ' ';
        // cout << i << ' ';
        for(int j = 0; j <= i; j++){
            //cout << j << ' ';
            if(j == 0) f[u][i] = max(f[u][i],f[s[1].first][i - j - 1] + s[1].second);
            else if(j == i) f[u][i] = max(f[u][i],f[s[2].first][j - 1] + s[2].second);
            else f[u][i] = max(f[u][i],f[s[1].first][j - 1] + f[s[2].first][i - j - 1] + s[2].second + s[1].second);
        }
    }
    //cout << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    Edge nowin;
    for(int i = 1; i < n; i++){
        cin >> nowin.from >> nowin.to >> nowin.val;
        edge[nowin.from].push_back(nowin);
        edge[nowin.to].push_back(Edge(nowin.to,nowin.from,nowin.val));
    }
    init(1,0);
    /*for(int i = 1 ;i <= n; i++){
        cout << sz[i] << ' ';
    }*/
    //cout << endl;
    dfs(1,0);
    cout << f[1][q] << endl;
    return 0;
}