#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,x,a,b;

signed main(){
    cin >> t;
    while(t--){
        cin >> x >> a >> b;
        if((a - 1) * x >= b) cout << x;
        else if(a == 1 && b != 0){
            cout << x - ((x / b) + 1) * b;
        }
        else{
            int prex;
            while(x >= 0){
                prex = x;
                x = a * x - b;
                if(prex <= x){
                    x = prex;
                    break;
                }
            }
            cout << x;
        }
        cout << "\n";
    }
    return 0;
}