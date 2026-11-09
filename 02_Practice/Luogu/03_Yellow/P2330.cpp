#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXM = 8005;
const int MAXN = 305;

struct Edge{
    int u,v,w;
};

Edge edge[MAXM];

bool cmp(Edge a, Edge b){
    return a.w < b.w;
}

int fa[MAXM];

void init(){
    for(int i = 1; i <= MAXN; i++){
        fa[i] = i;
    }
}

int find(int a){
    return (a == fa[a])? fa[a]:(fa[a] = find(fa[a]));
}

bool merge(int a,int b){
    int fa_a = find(a),fa_b = find(b);
    if(fa_a != fa_b){
        fa[fa_b] = fa_a;
        return 1;
    }
    return 0;
}


int n,m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    init();
    for(int i = 1; i <= m; i++){
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    sort(edge + 1,edge + 1 + m,cmp);
    int wmax = -1e9,cnt = 0;
    for(int i = 1; i <= m ; i++){
        if(merge(edge[i].u,edge[i].v)){
            wmax = max(wmax,edge[i].w);
            cnt++;
        }
    }    
    cout << cnt << ' ' << wmax << endl;
    return 0;
}