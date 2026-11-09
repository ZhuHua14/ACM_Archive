#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 5;
int n,s,h1,h2;
typedef struct Node{
    int high,s;
}Node;
bool cmp(Node x,Node y){
    return x.s < y.s;
}
Node llist[MAXN];
int main(){
    cin >> n >> s >> h1 >> h2;
    int maxh = h1 + h2;
    for(int i = 1; i <= n; i++){
        cin >> llist[i].high >> llist[i].s;
    }
    sort(llist + 1,llist + 1 + n,cmp);
    /*for(int i = 1; i <= n; i++){
        cout << llist[i].high << ' ' << llist[i].s << "\n";
    }*/
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(s - llist[i].s < 0){
            break;
        }
        if(maxh >= llist[i].high){
            ans++;
            s -= llist[i].s;
        }
    }
    cout << ans;
    return 0;
}