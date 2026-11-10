// P1363 幻象迷宫
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 15e2 + 5;
int n,m,startx,starty;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1}; 
char mm[MAXN][MAXN];
bool isRead[MAXN][MAXN];
pair<int,int> firstto[MAXN][MAXN];
bool flag = 0;

void init(){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            isRead[i][j] = 0;
            firstto[i][j] = (pair<int,int>){0,0};
        }
    }
}

void dfs(int x,int y){
    //cout << x << ' ' << y << ' ';
    int nowpx = (x % n + n) % n;
    int nowpy = (y % m + m) % m;
    //cout << nowpx << ' ' << nowpy << endl;
    if(flag){
        return;
    }
    if((x != firstto[nowpx][nowpy].first || y != firstto[nowpx][nowpy].second) && isRead[nowpx][nowpy]){
        flag = 1;
        return;
    }
    isRead[nowpx][nowpy] = 1;
    firstto[nowpx][nowpy] = (pair<int,int>){x,y};
    for(int i = 0; i <= 3; i++){
        int nextx = ((x + dx[i]) % n + n) % n;
        int nexty = ((y + dy[i]) % m + m) % m;
        if(mm[nextx][nexty] != '#' && ((isRead[nextx][nexty] == 0) || (x + dx[i] != firstto[nextx][nexty].first || y + dy[i] != firstto[nextx][nexty].second))){
            //cout << "    " << mm[nextx][nexty] << x << ' ' << nowpx << ' ' << y << ' ' << nowpy << ' ' << isRead[nowpx][nowpy] << endl;
            dfs(x + dx[i],y + dy[i]);
        }
    }
    return;
}

int main(){
    while(cin>>n>>m){
        init();
        //cout << 114514;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mm[i][j];
                if(mm[i][j] == 'S'){
                    startx = i;
                    starty = j;
                }
            }
        }
        flag = 0;
		dfs(startx,starty);
        if(flag == 0) cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
}