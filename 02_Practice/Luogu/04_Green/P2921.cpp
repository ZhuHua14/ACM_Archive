// P2921 [USACO08DEC] Trick or Treat on the Farm G
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int v[MAXN];
int n,nowans;
bool isread[MAXN];
int f[MAXN],cntofw[MAXN];
int ffrom;
int dfs(int k,int nowcnt){
    if(f[k] != 0) return nowcnt + f[k] - 1;
    if(isread[k] == 1){
        f[k] = nowcnt - cntofw[k];
        ffrom = k;
        nowans = nowcnt - 1;
        return nowans;
    }
    else{    
        isread[k] = 1;
        cntofw[k] = nowcnt;
        nowans = dfs(v[k],nowcnt + 1);
        if(ffrom != 0){
            f[k] = f[ffrom];
            if(ffrom == k) ffrom = 0;
        }
        else f[k] = f[v[k]] + 1;
        isread[k] = 0;
        return nowans;
    }    
}

int main(){
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    cin >> n;
    int nowt;
    for(int i = 1; i <= n; i++){
        cin >> nowt;
        v[i] = nowt;
    }
    for(int i = 1; i <= n; i++){
        cout << dfs(i,1) << endl;
    }
    return 0;
}