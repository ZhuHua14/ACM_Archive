// P1613 跑路
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 55;
const int MAXK = 31;
ll n,m;
bool f[MAXN][MAXN][MAXK];
vector<ll> edge[MAXN];

struct Node{
    ll cnt,dis;

    Node(): cnt(0),dis(0) {};
    Node(ll _cnt,ll _dis): cnt(_cnt),dis(_dis) {};

    bool operator>(const Node)const;
};

bool Node::operator>(const Node x)const{
    return dis > x.dis;
}

void dij(){
    priority_queue<Node,vector<Node>,greater<Node> > pq;
    ll dis[MAXN];
    bool vis[MAXN];
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    pq.push(Node(1,0));
    dis[1] = 0;
    Node nowtop;
    while(!pq.empty()){
        nowtop = pq.top();
        pq.pop();
        if(vis[nowtop.cnt] == 0){
            vis[nowtop.cnt] = 1;
            for(auto to:edge[nowtop.cnt]){
                if(dis[nowtop.cnt] + 1 < dis[to]){
                    dis[to] = dis[nowtop.cnt] + 1;
                    pq.push(Node(to,dis[to]));
                }
            }
        }
    }
    cout << dis[n] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ll nowf,nowt;
    for(int i = 1; i <= m; i++){
        cin >> nowf >> nowt;
        edge[nowf].push_back(nowt);
        f[nowf][nowt][1] = 1;
    }
    for(int k = 2; k <= MAXK; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                for(int l = 1; l <= n; l++){
                    f[i][j][k] |= f[i][l][k - 1] & f[l][j][k - 1];
                    if(f[i][j][k]) edge[i].push_back(j);
                }
            }
        }
    }
    dij();
    return 0;
}