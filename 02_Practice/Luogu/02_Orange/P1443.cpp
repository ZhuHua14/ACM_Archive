// P1443 马的遍历
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 405;
int ans[MAXN][MAXN];
pair<int,int> inpoint;
int dx[8] = {2,2,-2,-2,1,1,-1,-1};
int dy[8] = {1,-1,1,-1,2,-2,2,-2};
int n,m;
bool outofrange(pair<int,int> point){
    return point.first <= 0 || point.second <= 0 || point.first > n || point.second > m;
}
void init(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            ans[i][j] = -1;
        }
    }
}
int main(){
    cin >> n >> m >> inpoint.first >>  inpoint.second;
    init();
    ans[inpoint.first][inpoint.second] = 0;
    queue<pair<int,int> > q;
    q.push(inpoint);
    pair<int,int> nowtop;
    while(!q.empty()){
        nowtop = q.front();
        //cout << nowtop.first <<' ' << nowtop.second << "\n";
        q.pop();
        for(int i = 0; i <= 7; i++){
            if((!outofrange({nowtop.first + dx[i],nowtop.second + dy[i]}) && ans[nowtop.first + dx[i]][nowtop.second + dy[i]] == -1)){
                q.push({nowtop.first + dx[i],nowtop.second + dy[i]});
                if(ans[nowtop.first + dx[i]][nowtop.second + dy[i]] == -1){
                    ans[nowtop.first + dx[i]][nowtop.second + dy[i]] = ans[nowtop.first][nowtop.second] + 1;
                }
                ans[nowtop.first + dx[i]][nowtop.second + dy[i]] = min(ans[nowtop.first][nowtop.second] + 1,ans[nowtop.first + dx[i]][nowtop.second + dy[i]]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << ans[i][j] << ' ';
        }
        cout << "\n";
    }
    return 0;
}