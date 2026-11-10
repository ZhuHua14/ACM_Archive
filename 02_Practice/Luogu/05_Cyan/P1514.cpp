// P1514 [NOIP 2010 提高组] 引水入城
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e2 + 5;
const int INF = 0x3f3f3f3f;
int n,m,high[MAXN][MAXN];/*high[x][y]*/
bool isRead[MAXN][MAXN];
bool lastRead[MAXN][MAXN];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
pair<int,int> f[MAXN];/*.first = l,.second = r*/
bool outofrange(int x,int y){
    return x <= 0 || y <= 0 || x > m || y > n;
}

void init(){
    for(int i = 1; i <= m; i++){
        f[i].first = INF;
        f[i].second = -INF;
    }
}
bool cmp(pair<int,int> x,pair<int,int> y){
    if(x.first != y.first){
        return x.first < y.first;
    }
    else return x.second < y.second;
}

void bfs(int nowpx,int nowpy){
    queue< pair<int,int> > q;/*first = x,second = y*/
    
    q.push({nowpx,nowpy});
    isRead[nowpx][nowpy] = 1;
    pair<int,int> nowtop;
    while(!q.empty()){
        nowtop = q.front();
        q.pop();
        for(int i = 0; i <= 3; i++){
            if(!outofrange(nowtop.first + dx[i],nowtop.second  + dy[i])){       
                if(high[nowtop.first + dx[i]][nowtop.second  + dy[i]] < high[nowtop.first][nowtop.second] && (!isRead[nowtop.first + dx[i]][nowtop.second  + dy[i]])){
                    isRead[nowtop.first + dx[i]][nowtop.second  + dy[i]] = 1;
                    q.push({nowtop.first + dx[i],nowtop.second  + dy[i]});
                }
            }
        }
    }

    for(int i = 1 ; i <= n; i++){
       for(int j = 1; j <= m; j++){
           lastRead[j][i] = 0;
       }
    }
    q.push({nowpx,nowpy});
    lastRead[nowpx][nowpy] = 1;
    while(!q.empty()){
        nowtop = q.front();
        q.pop();                
        if(nowtop.second == n){
            f[nowpx].first = min(f[nowpx].first,nowtop.first);
            f[nowpx].second = max(f[nowpx].second,nowtop.first); 
        }  
        for(int i = 0; i <= 3; i++){
            if(!outofrange(nowtop.first + dx[i],nowtop.second  + dy[i])){   
                if(high[nowtop.first + dx[i]][nowtop.second  + dy[i]] < high[nowtop.first][nowtop.second] && (!lastRead[nowtop.first + dx[i]][nowtop.second  + dy[i]])){
                    lastRead[nowtop.first + dx[i]][nowtop.second  + dy[i]] = 1;
                    q.push({nowtop.first + dx[i],nowtop.second  + dy[i]});
                }
            }
        }
    }
}

int ans[MAXN];

int main(){
    cin >> n >> m;
    init();
    for(int i = 1 ; i <= n; i++){
       for(int j = 1; j <= m; j++){
           cin >> high[j][i];
       }
    }
    memset(isRead,0,sizeof(isRead));
    for(int i = 1; i <= m; i++){
       bfs(i,1);
    }
    bool flag = 1;
    int ans = 0;
    for(int i = 1; i <= m; i++){
        if(isRead[i][n] == 0){
            flag = 0;
            ans++;
        }
    }
    cout << (int)(flag) << "\n";
    if(flag == 0){
        cout << ans;
        return 0;
    }
    else{
        ans = 0;       
        //for(int i = 1; i <= m; i++){
        //    cout << i << ':' << f[i].first << ' ' << f[i].second << "\n";
        //}
        sort(f + 1,f + m + 1,cmp);
        //for(int i = 1; i <= m; i++){
        //    cout << f[i].first << ' ' << f[i].second << "\n";
        //}
        int i = 1, nowl = f[1].first, nowr;
        while(i <= m && nowl <= m){
            nowr = -1;
            while(nowl >= f[i].first){
                nowr = max(nowr,f[i].second);
                i++;
            }
            nowl = nowr + 1;
            ans++;
        }
        cout << ans;
    }
    return 0;
}