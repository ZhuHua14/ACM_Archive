// P1223 排队接水
 #include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
struct node{
    int cnt,value;
}t[MAXN];
bool cmp(node x,node y){
    return x.value < y.value;
}

int n,sum[MAXN];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> t[i].value;
        t[i].cnt = i;
    }
    sort(t + 1, t + n + 1,cmp);
    double nowsum = 0;
    for(int i = 1; i <= n; i++){
        cout << t[i].cnt << ' ';
        sum[i + 1] = sum[i] + t[i].value;
        nowsum += sum[i];
    }
    double nowave = nowsum / n;
    printf("\n%.2lf",nowave);
    return 0;
}