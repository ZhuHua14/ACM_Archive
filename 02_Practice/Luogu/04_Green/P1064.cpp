// P1064 [NOIP 2006 提高组] 金明的预算方案
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 65;
const int MAXM = 3.2e4 + 5;

struct Node{
    int imp,val;
};

Node llist[MAXN];

struct Tree{
    int s[5],cnt;
};
Tree node[MAXN];

int rootcnt,root[MAXN];

int n,m,f[MAXN][MAXM];
int main(){
    cin >> n >> m;
    int nowroot;
    for(int i = 1; i <= m; i++){
        cin >> llist[i].val >> llist[i].imp >> nowroot;
        if(!nowroot) root[++rootcnt] = i;
        else{
            node[nowroot].s[node[nowroot].cnt] = i;
            node[nowroot].cnt++;
        }
    }
    int v0,v1,v2,v12;
    int ans0,ans1,ans2,ans12;
    for(int i = 1; i <= rootcnt; i++){
        for(int j = 1; j <= n; j++){
            v0 = llist[root[i]].val;
            v1 = v0 + llist[node[root[i]].s[0]].val;
            v2 = v0 + llist[node[root[i]].s[1]].val;
            v12 = v1 + v2 - v0;
            ans0 = llist[root[i]].val * llist[root[i]].imp;
            ans1 = ans0 + llist[node[root[i]].s[0]].val * llist[node[root[i]].s[0]].imp;
            ans2 = ans0 + llist[node[root[i]].s[1]].val * llist[node[root[i]].s[1]].imp;
            ans12 = ans1 + ans2 - ans0;            
            if(j >= v0) f[i][j] = max(f[i][j],f[i - 1][j - v0] + ans0);
            if(j >= v1) f[i][j] = max(f[i][j],f[i - 1][j - v1] + ans1);
            if(j >= v2) f[i][j] = max(f[i][j],f[i - 1][j - v2] + ans2);
            if(j >= v12) f[i][j] = max(f[i][j],f[i - 1][j - v12] + ans12);
            f[i][j] = max(f[i][j],f[i - 1][j]);
        }
    }
    cout << f[rootcnt][n] << endl;
    return 0;
}