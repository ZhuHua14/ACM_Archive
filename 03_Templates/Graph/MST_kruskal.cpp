#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 5e3 + 5;
const int MAXM = 2e5 + 5;
struct Edge{
    ll from,to,val;

    Edge(ll _from,ll _to,ll _val): from(_from),to(_to),val(_val){}
    Edge(){}

    bool operator<(const Edge)const;
};

bool Edge::operator<(const Edge e)const{
    return val < e.val; 
}

Edge edge[MAXM];
ll n,m,nxt[MAXM],head[MAXN],cnt = 0;
/*void insert_edge(Edge e){
    edge[++cnt] = e;
    nxt[head[e.from]] = cnt;
    head[e.from] = cnt;
}*/

ll fa[MAXN];

void init(){
    for(int i = 1; i <= n; i++){
        fa[i] = i;
    }
}
ll find(ll a){
    return (a == fa[a])? fa[a]:(fa[a] = find(fa[a]));
}

bool marge(ll a,ll b){
    ll fa_a = find(a),fa_b = find(b);
    if(fa_a != fa_b){
        fa[fa_b] = fa_a;
        return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    init();
    Edge nowin;
    for(int i = 1; i <= m; i++){
        cin >> edge[i].from >> edge[i].to >> edge[i].val;
    }
    sort(edge + 1,edge + 1 + m);
    ll ans = 0,ecnt = 0;
    for(int i = 1; i <= m; i++){
        if(marge(edge[i].from,edge[i].to)){
            ans += edge[i].val;
            ecnt++;
        }
    }
    ll flag = 0;
    for(int i = 1; i <= n; i++){
        if(fa[i] == i) flag++;
    }
    if(flag > 1) cout << "orz" << endl;
    else cout << ans << endl;
    return 0;
}