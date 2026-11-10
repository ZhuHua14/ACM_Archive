// P1757 通天之分组背包
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
const int MAXK = 105;
struct Node{
    int w,val;
};
Node create(int w,int val){
    Node ans;
    ans.val = val;
    ans.w = w;
    return ans;
}

vector<Node> node[MAXK];
int n,m,f[MAXN];
int main(){
    //freopen("test.err","w",stderr);
    cin >> m >> n;
    int v,w,cnt,maxcnt = 0;
    for(int i = 1; i <= n; i++){
        cin >> w >> v >> cnt;
        node[cnt].push_back(create(w,v));
        maxcnt = max(maxcnt,cnt);
    }
    for(int i = 1; i <= maxcnt; i++){
        for(int k = m; k >= 0; k--){        
            for(int j = 0; j < node[i].size(); j++){
                //cerr << i << ' ' << k << ' ' << j << ':' << node[i][j].w << ' ' << node[i][j].val << ' ' << f[i][k] << ' ';
                if(k >= node[i][j].w){
                    f[k] = max(f[k],f[k - node[i][j].w] + node[i][j].val);
                    //cerr << f[i - 1][k - node[i][j].w] + node[i][j].val << ' ' << f[i - 1][k] << endl;
                }
            }
        }
    }
    /*for(int i = 1; i <= maxcnt; i++){
        cout << f[i][m] << ' ';
    }*/
    cout << f[m];
    return 0;
}