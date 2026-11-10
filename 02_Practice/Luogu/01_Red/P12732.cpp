// P12732 外人
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 15; 


int n,y[MAXN],s[MAXN];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> y[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    int ans = 0;
    for(int i = 2; i <= n; i++){
        if((s[i - 1] > y[i - 1] && s[i] > y[i]) || (s[i - 1] < y[i - 1] && s[i] < y[i])){
            continue;
        }
        ans++;
    }
    cout << ans;
    return 0;
}