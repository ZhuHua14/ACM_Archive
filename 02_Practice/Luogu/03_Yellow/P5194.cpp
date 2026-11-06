#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e3 + 5;
int m[MAXN],sum[MAXN],n,c;
//bool isread[MAXN];
int ans = -0x3f3f3f3f3f3f3f3f;
void dfs(int nowp,int nowm){
    //cout << nowp << "\n";
    if(nowp <= 0){
        ans = max(ans,nowm);
        return;
    }
    if(nowm + sum[nowp - 1] < c){
        ans = max(nowm + sum[nowp - 1],ans);
        return;
    }
    if(nowm + m[nowp - 1] < c){
        dfs(nowp - 1,nowm + m[nowp - 1]); 
    }
    dfs(nowp - 1, nowm);
}
signed main(){
    cin >> n >> c;
    for(int i = 1; i <= n; i++){
        cin >> m[i];
        sum[i] = sum[i - 1] + m[i];
    }
    /*/for(int i = n; i >= 1; i++){
        //memset(isread,0,sizeof(isread));
        dfs(i,m[i]);
    }*/
    dfs(n + 1,0);
    cout << ans;
    return 0;
}