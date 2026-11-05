#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
typedef struct Node{
    int w,val;
    double valpw;
}Node;
Node node[MAXN];
bool cmp(Node x,Node y){
    return x.valpw > y.valpw;
}
int n,t;

int main(){
    cin >> n >> t;
    for(int i = 1; i <= n; i++){
        cin >> node[i].w >> node[i].val;
        node[i].valpw = (double)(node[i].val) / (double)(node[i].w);
    }
    sort(node + 1,node + 1 + n,cmp);
    double ans = 0.0;
    for(int i = 1; i <= n; i++){
        if(t - node[i].w < 0){
            ans += node[i].valpw * t;
            break; 
        }
        ans += node[i].val;
        t -= node[i].w;
    }
    printf("%.2lf",ans);
    return 0;
}