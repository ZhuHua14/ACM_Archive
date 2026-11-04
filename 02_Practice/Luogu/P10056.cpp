#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,n;
signed main(){
    cin >> a >> b >> n;
    cout << min((a/b) * b,b * n);
    return 0;
}