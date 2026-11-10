// P1031 [NOIP 2002 提高组] 均分纸牌
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 4;
int llist[MAXN],n,ave;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> llist[i];
        ave += llist[i];
    }
    ave /= n;
    int nowdx,ans = 0;
    for(int i = 1; i <= n; i++){
        if(llist[i] == ave){
            continue;
        }
        else{
            nowdx = llist[i] - ave;
            llist[i + 1] += nowdx;
            ans++;
        }
    }
    cout << ans;
    return 0;
}