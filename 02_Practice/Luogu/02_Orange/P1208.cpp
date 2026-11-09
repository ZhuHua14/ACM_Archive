#include<bits/stdc++.h>
using namespace std;
const int MAXM = 5e3 + 5;
typedef struct Node{
    int p,a;
}Node;
Node llist[MAXM];
bool cmp(Node x,Node y){
    return x.p < y.p;
}
int n,m;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> llist[i].p >> llist[i].a;
    }
    sort(llist + 1,llist + 1 + m,cmp);
    int nowans = 0;
    for(int i = 1; i <= m; i++){
        if(n - llist[i].a <= 0){
            nowans += n * llist[i].p;
            break;
        }
        else{
            nowans += llist[i].a * llist[i].p;
            n -= llist[i].a;
        }
    }
    cout << nowans;
    return 0;
}