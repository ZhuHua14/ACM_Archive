// P2853 [USACO06DEC] Cow Picnic S
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;

vector<int> edge[MAXN];
int n,m,k,cows[105],canto[MAXN];
bool isread[MAXN];
void dfs(int k){
//    cout << k << ":\n" <<isread[k];
    isread[k] = 1;
    canto[k]++;
//    cout << canto[k] << '\n';
    for(int i = 0; i < edge[k].size(); i++){
        if(isread[edge[k][i]] == 0){
            dfs(edge[k][i]);
        }
    }
}

int main(){
    cin >> k >> n >> m;
    for(int i = 1; i <= k; i++){
        cin >> cows[i];
//        cout << ' ' << cows[i];
    }
    int nowf,nowt;
//   cout << '\n';
    for(int i = 1; i <= m; i++){
        cin >> nowf >> nowt;
        edge[nowf].push_back(nowt);
//       cout << edge[nowf][edge[nowf].size() - 1] << "\n";
    }
    for(int i = 1; i <= k; i++){
        memset(isread,0,sizeof(isread));
        dfs(cows[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        //cout << canto[i] << ' ';
        if(canto[i] == k){
            ans++;
        }
    }
    cout << ans;
    return 0;
}