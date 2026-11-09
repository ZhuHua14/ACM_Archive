#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            int nowout = i / 2 * (i % 2 == 1? 1:-1);
            cout << nowout << ' ';
        }
        cout << endl;
    }
    return 0;
}