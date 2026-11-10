// P5710 【深基3.例2】数的性质
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int p;
    bool flag1 = 0,flag2 = 0;
    cin >> p;
    flag1 = !(p & 1);
    if(p > 4 && p <= 12) flag2 = 1;
    //cerr << flag1 << ' ' << flag2 << ' '; 
    cout << (flag1 && flag2) << ' ';
    cout << (flag1 || flag2) << ' ';
    cout << (flag1 ^ flag2) << ' ';
    cout << !(flag1 || flag2) << ' ';
    return 0;
}