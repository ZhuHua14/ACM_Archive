#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10;
int mmap[MAXN][MAXN];
bool isread[MAXN][MAXN];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ans,n,m,t,startx,starty,finalx,finaly;
bool outofrange(int x,int y){
    return x <= 0 || y <= 0 || x > n || y > m;
}


void dfs(int nowpx,int nowpy){
    if(nowpx == finalx && nowpy == finaly){
        ans++;
        return;
    }
    isread[nowpx][nowpy] = 1;
    for(int i = 0; i <= 3; i++){
        if(outofrange(nowpx + dx[i],nowpy + dy[i])) continue;
        if(isread[nowpx + dx[i]][nowpy + dy[i]] == 1) continue;
        if(mmap[nowpx + dx[i]][nowpy + dy[i]] == 1) continue;
        isread[nowpx + dx[i]][nowpy + dy[i]] = 1;
        dfs(nowpx + dx[i],nowpy + dy[i]);
        isread[nowpx + dx[i]][nowpy + dy[i]] = 0;
    }
}
int main(){
    cin >> n >> m >> t;
    cin >> startx >> starty >> finalx >> finaly;
    int nowx,nowy;
    for(int i = 1; i <= t; i++){
        cin >> nowx >> nowy;
        mmap[nowx][nowy] = 1;
    }
    dfs(startx,starty);
    cout << ans;
    return 0;
}