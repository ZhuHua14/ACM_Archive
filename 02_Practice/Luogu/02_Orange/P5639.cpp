#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;

int n,llist[MAXN];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> llist[i];
    }
    int ans = 1;
    for(int i = 1; i <= n; i++){
        if(llist[i - 1] != llist[i]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}