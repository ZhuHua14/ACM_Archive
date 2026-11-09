#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
const int MAXM = 2e5 + 5;
const int IMPOSSIBLE = 1e8;

struct Edge{
    int from,to,next;
};
int head[MAXN],ecnt;
Edge edge[MAXM];
bool pisread[MAXN];
void insert(int f,int t){
    edge[++ecnt].from = f;
    edge[ecnt].to = t;
    edge[ecnt].next = head[f];
    head[f] = ecnt;
}

int wcnt,bcnt;
bool color[MAXN]/*0 = w;1 = b*/;
bool flag;
int bfs(int f){
    color[f] = 0;
    wcnt = 1;
    bcnt = 0;
    pisread[f] = 1;
    queue<int> q;
    q.push(f);
    int nowtop;
    while(!q.empty()){
        nowtop = q.front();
        q.pop();
        for(int nowp = head[nowtop]; nowp; nowp = edge[nowp].next){
            int nowt = edge[nowp].to;
            if(pisread[nowt] == 1){
                if(color[nowt] == color[nowtop]) return IMPOSSIBLE;
                else continue;
            }
            if(color[nowtop] == 0) color[nowt] = 1;
            else color[nowt] = 0;
            pisread[nowt] = 1;
            if(color[nowt] == 0) wcnt++;
            else bcnt++;
            q.push(nowt);
        }
    }
    return min(wcnt,bcnt);
}


int n,m;
int main(){
    cin >> n >> m;
    int nowf,nowt;
    for(int i = 1; i <= m; i++){
        cin >> nowf >> nowt;
        insert(nowf,nowt);
        insert(nowt,nowf);
    }
    int nowans = 0,finalans = 0;
    for(int i = 1; i <= n; i++){ 
        if(pisread[i] == 1){
            continue;
        }  
        nowans = bfs(i);
        //cout<<i<<':'<<wcnt<<' '<<bcnt<<'\n';
        if(nowans == IMPOSSIBLE){
            cout << "Impossible";
            return 0;
        }
        finalans += nowans;
    }
    cout << finalans;
    return 0;
}