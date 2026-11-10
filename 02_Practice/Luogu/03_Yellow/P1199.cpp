// P1199 [NOIP 2010 普及组] 三国游戏
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 505;
typedef struct Node{
    int to,val;
}Node;
vector<Node> llist[MAXN];
Node Create(int t,int v){
    Node create;
    create.to = t;
    create.val = v;
    return create;
}
bool cmp(Node x,Node y){
    return x.val > y.val;
}
int n;
int main(){
    cin >> n;
    int nowval;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            cin >> nowval;
            llist[i].push_back(Create(j,nowval));
            llist[j].push_back(Create(i,nowval));
        }
    }
    int nowans = -1;
    for(int i = 1; i <= n; i++){
        sort(llist[i].begin(),llist[i].end(),cmp);
        nowans = max(nowans,llist[i][1].val);
    }
    cout << 1 << "\n" << nowans;
    return 0;
}