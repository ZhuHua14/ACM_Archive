// P1111 修复公路
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
const int MAXM = 1e5 + 5;
typedef struct Edge{
    int from,to,val;
}Edge;
Edge edge[MAXM];
bool cmp(Edge x,Edge y){
    return x.val < y.val;
}
int fa[MAXN],n,m;

void init(){
    for(int i = 0; i <= n; i++){
        fa[i] = i;
    }
}

int find(int x){
    return (fa[x] == x)? x:(fa[x] = find(fa[x]));
}

void marge(int f,int s){
    int ff = find(f),fs = find(s);
    if(ff == fs) return;
    n--;
    fa[fs] = ff;
}

int main(){
    cin >> n >> m;
    init();
    for(int i = 1; i <= m; i++){
        cin >> edge[i].from >> edge[i].to >> edge[i].val;
    }
    sort(edge + 1,edge + m + 1,cmp);
    for(int i = 1; i <= m; i++){
        marge(edge[i].from,edge[i].to);
        if(n == 1){
            cout << edge[i].val;
            return 0;
        }
    }
    cout << -1;
    return 0;
}