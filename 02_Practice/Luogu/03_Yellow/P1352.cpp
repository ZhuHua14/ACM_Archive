// P1352 没有上司的舞会
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 6e3 + 5;
vector<int> v[MAXN];
int f[MAXN][2],r[MAXN],n,incnt[MAXN];
void dfs(int nowroot){
    f[nowroot][0] = 0;
    f[nowroot][1] = r[nowroot];
    for(int i = 0; i < v[nowroot].size(); i++){
        dfs(v[nowroot][i]);
        f[nowroot][0] += max(f[v[nowroot][i]][0],f[v[nowroot][i]][1]);
        f[nowroot][1] += f[v[nowroot][i]][0];
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> r[i];
    }
    int nowf = 0,nows = 0;
    for(int i = 1; i < n; i++){
        cin >> nows >> nowf;
        v[nowf].push_back(nows);
        incnt[nows]++;
    }
    int root = 0;
    for(int i = 1; i <= n; i++){
        if(incnt[i] == 0) root = i;
        //cout << root;
    }
    dfs(root);
    /*for(int i = 0; i <= 1; i++){
        for(int j = 1; j <= n; j++){
            cout << f[j][i] << ' ';
        }
    cout << endl;
    }*/
    cout << max(f[root][0],f[root][1]);
    return 0;
}