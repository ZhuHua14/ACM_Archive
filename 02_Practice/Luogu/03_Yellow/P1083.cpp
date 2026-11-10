// P1083 [NOIP 2012 提高组] 借教室
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e6 + 5;
const int MAXM = 1e6 + 5;
typedef struct Node{
    int cnt,from,to;
}Node;
Node node[MAXM];
int n,m,r[MAXN],dis[MAXN];
int nowdis[MAXN],nowr[MAXM];
bool check(int k){/*第k个会不会出现无法完全满足？ 会 return 1 往小了找 不会 return 0 往大了找*/
    //cout << nowp << ' ' <<  k << ":";
    for(int i = 1; i <= n; i++){
        nowdis[i] = dis[i];
    }
    memset(nowr,0,sizeof(nowr));
    for(int i = 1; i <= k; i++){
        nowdis[node[i].from] -= node[i].cnt;
        nowdis[node[i].to + 1] += node[i].cnt;
    }
    /*for(int i = 1; i <= n; i++){
        cout << dis[i] << ' ';
    }
    cout << "\n";*/
    bool flag = 0;
    for(int i = 1; i <= n; i++){
        nowr[i] = nowr[i - 1] + nowdis[i];
        if(nowr[i] < 0){
            flag = 1;
            break;
        }
    }
    return flag;
}
signed main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> r[i];
    }
    for(int i = 1; i <= n; i++){
        dis[i] = r[i] - r[i - 1];
    }
    for(int i = 1; i <= m; i++){
        cin >> node[i].cnt >> node[i].from >> node[i].to;
    }
    int left = 1,right = m,ans;
    while(left < right){
        int mid = (left + right) / 2;
        if(check(mid)){
            ans = mid;
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    if(!check(m)){
        cout << 0;
    }
    else cout << -1 << '\n'<< ans;
    return 0;
}