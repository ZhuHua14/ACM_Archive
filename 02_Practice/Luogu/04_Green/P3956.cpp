// P3956 [NOIP 2017 普及组] 棋盘
#include<bits/stdc++.h>
using namespace std;
const int MAXM = 105;
int mmap[MAXM][MAXM],m,n;
int ans[MAXM][MAXM];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
typedef struct Node{
    int x,y,color,value;
}Node;
Node Create(int x,int y,int color,int val){
    Node create;
    create.x = x;
    create.y = y;
    create.color = color;
    create.value = val;
    return create;
}

void init(){
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            ans[i][j] = -1;
            mmap[i][j] = -1;
            //cout << ans[i][j] << ' ';
        }
        //cout << "\n";
    }
}

bool outofrange(int x,int y){
    return x <= 0 || y <= 0 || x > m || y > m;
}

void bfs(){
    queue<Node> q;
    q.push(Create(1,1,mmap[1][1],0));
    Node nowtop,tonode;
    int nowcost,nowcolor,tocolor;
    while(!q.empty()){
        nowtop = q.front();
        q.pop();
        //cout << nowtop.color;
        //cout << nowtop.x << ' ' << nowtop.y << ' ' << nowtop.color <<"\n";
        if(ans[m][m] != -1 && nowtop.value > ans[m][m]){
            continue;
        }
        if(nowtop.x == m && nowtop.y == m){
            continue;
        }
        for(int i = 0; i <= 3; i++){
            tonode = Create(nowtop.x + dx[i],nowtop.y + dy[i],mmap[nowtop.x + dx[i]][nowtop.y + dy[i]],ans[nowtop.x + dx[i]][nowtop.y + dy[i]]);
            nowcolor = mmap[nowtop.x][nowtop.y];
            if(!outofrange(tonode.x,tonode.y)){
                if(nowcolor != -1 && tonode.color != -1){
                    if(nowtop.color == tonode.color) nowcost = 0;
                    else nowcost = 1;
                    if(ans[tonode.x][tonode.y] == -1 || (tonode.value > nowtop.value + nowcost)){
                        tonode.value = nowtop.value + nowcost;
                        q.push(tonode);
                        ans[tonode.x][tonode.y] = tonode.value;

                    }
                }
                else if(nowcolor != -1 && tonode.color == -1){
                    nowcost = 2;
                    tonode.color = nowcolor;
                    if(ans[tonode.x][tonode.y] == -1 || (tonode.value > nowtop.value + nowcost)){
                        tonode.value = nowtop.value + nowcost;
                        q.push(tonode);
                        ans[tonode.x][tonode.y] = tonode.value;
                        
                    }
                }
                else if(nowcolor == -1 && tonode.color != -1){
                    if(nowtop.color == tonode.color) nowcost = 0;
                    else nowcost = 1;
                    if(ans[tonode.x][tonode.y] == -1 || (tonode.value > nowtop.value + nowcost)){
                        tonode.value = nowtop.value + nowcost;
                        q.push(tonode);
                        ans[tonode.x][tonode.y] = tonode.value;
                        
                    }
                }
            }   
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin >> m >> n;
    init();
    int nowx,nowy,nowcolor;
    for(int i = 1; i <= n; i++){
        cin >> nowx >> nowy >> nowcolor;
        mmap[nowx][nowy] = nowcolor;
    }
    ans[1][1] = 0;
    //cout << "\n";
    bfs();
    cout << ans[m][m];
    return 0;
}