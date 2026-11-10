// P13712 淘汰（Easy ver.）
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = INT_MAX;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x,y,a,b,c,d,T;
    cin >> T;
    while(T--){
        cin >> x >> y >> a >> b >> c >> d;
        int ans = INF;
        if(x == y) ans = min(ans,0);
        if((x | b) == y) ans = min(ans,d);
        if((x & a) == y) ans = min(ans,c);
        if(((x | b) & a) == y) ans = min(ans,c + d);
        if(((x & a) | b) == y) ans = min(ans,c + d);
        cout << (ans == INF? -1 : ans) << '\n';
    }
   return 0;
}