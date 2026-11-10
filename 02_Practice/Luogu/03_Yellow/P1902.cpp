// P1902 刺杀大使
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
int point[MAXN][MAXN],n,m;/*第（第一维）行第（第二维）列*/
bool isread[MAXN][MAXN];
void init(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            isread[i][j] = 0;
        }
    }
}
bool outofrange(int x,int y){
    return x <= 0 || y <= 0 || x > n || y > m;
}
int dx[4] = {0,0,-1,1},dy[4] = {-1,1,0,0};
bool check(int k){
    init();
    queue<pair<int,int> > q;
    q.push({1,1});
    pair<int,int> nowtop;
    while(!q.empty()){
        nowtop = q.front();
        q.pop();
        if(nowtop.first == n){
            return 1;
        }
        for(int i = 0; i <= 3; i++){
            if(point[nowtop.first + dx[i]][nowtop.second + dy[i]] <= k && !outofrange(nowtop.first + dx[i],nowtop.second + dy[i]) && !isread[nowtop.first + dx[i]][nowtop.second + dy[i]]){
                isread[nowtop.first + dx[i]][nowtop.second + dy[i]] = 1;
                q.push({nowtop.first + dx[i],nowtop.second + dy[i]});
            }
        }
    }
    return 0;
}
int main(){
    int maxin = -0x3f3f3f3f;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> point[i][j];
            maxin = max(maxin,point[i][j]);
        }
    }
    int l = 1,r = maxin,mid,ans;
    while(l < r){
        mid = (l + r) / 2;
        //cout << mid << " " << check(mid) << endl;
        if(check(mid)){
            ans = mid;
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}