#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e2 + 5;
const int MAXK = 1e2 + 5;
int n,k,m,maxcnt[MAXK];
struct Node{
    int val,type;
}node[MAXN];
bool cmp(Node x,Node y){
    return x.val > y.val;
}
bool isread[MAXN];
int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++){
        cin >> maxcnt[i]; 
    }
    for(int i = 1; i <= n; i++){
        cin >> node[i].val >> node[i].type;
    }
    sort(node + 1, node + 1 + n,cmp);
    int nowcnt = 0,ans = 0;
    for(int i = 1; i <= n; i++){
        if(nowcnt >= m){
            break;
        }
        if(maxcnt[node[i].type] > 0){
            ans += node[i].val;
            maxcnt[node[i].type]--;
            nowcnt++;
        }
    }
    cout << ans;
    return 0;
}