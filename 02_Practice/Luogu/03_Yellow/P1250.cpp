#include<bits/stdc++.h>
using namespace std;
const int MAXH = 5e3 + 5;
const int MAXN = 3e4 + 5;
struct node{
    int r,l,cnt;
}llist[MAXH];
bool isread[MAXN];
bool cmp(node x,node y){
    return x.r < y.r;
}
int main(){
    //freopen("in.txt","r",stdin);
    int n,h;
    cin >> n >> h;
    for(int i = 1; i <= h; i++){
        cin >> llist[i].l >> llist[i].r >> llist[i].cnt;
    }
    sort(llist + 1,llist + 1 + h,cmp);
    int nowl,nowr,nowcnt;
    for(int i = 1; i <= h; i++){
        nowl = llist[i].l;
        nowr = llist[i].r;
        nowcnt = llist[i].cnt;
        for(int j = nowl; j <= nowr; j++){
            if(isread[j] == 1){
                nowcnt--;
            }
        }
        while(nowcnt > 0){
            if(isread[nowr] == 0){
                isread[nowr] = 1;
                nowcnt--;
            }
            nowr--;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(isread[i]) ans++;
    }
    cout << ans;
    return 0;
}