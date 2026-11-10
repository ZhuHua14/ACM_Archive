// P1434 [SHOI2002] 滑雪
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

int r,c,a[MAXN][MAXN],f[MAXN][MAXN];

bool isout(int x,int y){
    return x > r || y > c || x <= 0 || y <= 0;
}

int dfs(int x,int y){
    if(f[x][y] != 0) return f[x][y];
    int nowans = 1;
    for(int i = 0; i < 4; i++){
        if((!isout(x + dx[i],y + dy[i])) && a[x][y] > a[x + dx[i]][y + dy[i]]){
            nowans = max(nowans,dfs(x + dx[i],y + dy[i]) + 1);
            f[x][y] = nowans;
        }
    }
    return nowans;
}

int main(){
    cin >> r >> c;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> a[i][j];
        }
    }
    int finalans = 0;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            finalans = max(finalans,dfs(i,j));
        }
    }
    cout << finalans << endl;
    return 0;
}