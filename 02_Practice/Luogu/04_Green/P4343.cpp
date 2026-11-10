// P4343 [SHOI2015] 自动刷题机
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f3f3f3f3f;
int llist[MAXN];
int n,k;    
int nowlen = 0,nowcnt = 0;
int check(int nown){
    nowlen = 0;
    nowcnt = 0;
    for(int i = 1; i <= n; i++){
        nowlen += llist[i];
        if(nowlen >= nown){
            nowcnt++;
            nowlen = 0;
        }
        if(nowlen < 0){
            nowlen = 0;
        }
    }
    return nowcnt;
}
signed main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> llist[i];
    }
    int l = 1,r = INF,ans = INF;
    while(l < r){
        int mid = (l + r) >> 1;
        //cout << mid << ' ';
        if(check(mid) > k){
            l = mid + 1;
        }
        else{
            r = mid;
        }
        if(nowcnt == k){
            ans = min(mid,ans);
        }
    }
    if(ans == INF){
        cout << -1;
        return 0;
    }
    cout << ans << ' ';
    l = 1;
    r = INF;  
    ans = -INF;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid) >= k){
            l = mid + 1;
        }
        else{
            r = mid;
        }
        if(nowcnt == k){
            ans = max(ans,mid);
        }
    }
    if(ans == -INF){
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;
}