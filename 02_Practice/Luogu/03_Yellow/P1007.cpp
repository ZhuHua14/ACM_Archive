// P1007 独木桥
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 5;
int bridge[MAXN],nowmax,nowmin,ansmax = 0,ansmin = 0,l,n;

int main(){
    cin >> l >> n;
    for(int i = 1; i <= n; i++){
        cin >> bridge[i];
        nowmax = max(bridge[i],l - bridge[i] + 1);
        nowmin = min(bridge[i],l - bridge[i] + 1);
        ansmax = max(ansmax,nowmax);
        ansmin = max(ansmin,nowmin);
    }
    cout << ansmin << ' ' << ansmax;
    return 0;
}