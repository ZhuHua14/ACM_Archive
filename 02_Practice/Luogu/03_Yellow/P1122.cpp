// P1122 最大子树和
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1.6e5 + 5;

int n,f[MAXN],a[MAXN];
vector<int> tree[MAXN];
bool isread[MAXN];
void dfs(int fa,int u){
    if(isread[u]) return;
    f[u] = a[u];
    isread[u] = 1;
    /*if(outcnt[fa] == 0){
        return;
    }*/
    for(int i = 0; i < tree[u].size(); i++){
        if(tree[u][i] != fa) dfs(u,tree[u][i]);
    }
    for(int i = 0; i < tree[u].size(); i++){
        if(tree[u][i] != fa) f[u] += max(f[tree[u][i]],0);
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int from,to;
    for(int i = 1; i < n; i++){
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }
    dfs(0,1);
    int maxf = -1e9;
    for(int i = 1; i <= n; i++){
        //cout << f[i] << ' ';
        maxf = max(maxf,f[i]);
    }
    cout << maxf << endl;
    return 0;
}