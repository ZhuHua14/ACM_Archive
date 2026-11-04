#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a[4];
    cin >> a[1] >> a[2] >> a[3];
    sort(a + 1,a + 1 + 3);
    cout << a[1] << ' ' << a[2] << ' ' << a[3];
    return 0;
}