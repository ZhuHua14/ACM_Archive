#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f3f3f3f3f;
pair<int,int> node[MAXN];/*f = l,s = r*/
pair<int,int> llist[MAXN];/*f = w,s = v*/
int n,m,s;

int nowans,sum[MAXN],cnt[MAXN];
bool check(int w)/*以此w算出的y比s大（return 1）或小（return 0）*/{
    memset(sum,0,sizeof(sum));
    memset(cnt,0,sizeof(cnt));
    for(int i = 1; i <= n; i++){
        if(llist[i].first >= w){
            sum[i] = sum[i - 1] + llist[i].second;
            cnt[i] = cnt[i - 1] + 1;
        }
        else{
            sum[i] = sum[i - 1];
            cnt[i] = cnt[i - 1];
        }
    }
    nowans = 0;
    int nowcnt,nowsum;
    for(int i = 1; i <= m; i++){
        nowcnt = cnt[node[i].second] - cnt[node[i].first - 1];
        nowsum = sum[node[i].second] - sum[node[i].first - 1];
        nowans += (nowcnt * nowsum); 
    }
    return nowans > s;
}
signed main(){
    int maxin = -INF,minin = INF;
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++){
        cin >> llist[i].first >> llist[i].second;
        maxin = max(maxin,llist[i].first);
        minin = min(minin,llist[i].first);
    }
    for(int i = 1; i <= m; i++){
        cin >> node[i].first >> node[i].second;
    }
    int l = 0,r = INF,ans = INF;
    //cout << l << r;
    while(l < r){
        //cout << 114514;
        int mid = (l + r) / 2;
        if(check(mid)){
            l = mid + 1;
        }
        else{
            r = mid;
        }
        //cout << ' ' << mid;
        ans = min(ans,llabs(s - nowans));
    }
    cout << ans;
    return 0;
}