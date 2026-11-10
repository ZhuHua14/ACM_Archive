// P2695 骑士的工作
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e4 + 5;
int n,m,head[MAXN],value[MAXN];
bool isread[MAXN];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> head[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> value[i];
    }      
    int ans = 0;
    sort(value + 1,value + 1 + m);
    sort(head + 1,head + 1 + n);
    if(n > m){
        cout << "you died!";
        return 0;
    }
    int j = 1;
    bool flag = 0;
    for(int i = 1; i <= n; i++){
        while(value[j] < head[i] && j <= m) j++;
        if(j > m) {
            flag = 1;
            break;
        }
        ans += value[j];
        j++;
    }
    if(flag){
        cout << "you died!";
        return 0;
    }
    cout << ans;
    return 0;
}