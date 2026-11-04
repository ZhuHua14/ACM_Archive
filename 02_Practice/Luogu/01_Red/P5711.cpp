#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool chk(int y){
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int y,m;
    cin >> y /*>> m*/;
    if(chk(y)){
        cout << "1";
    }
    else{
        cout << "0";
    }
    // cout << '\n';
    // if(m >= 1 && m <= 12){
    //     cout << "YES";
    // }
    // else{
    //     cout << "NO";
    // }
    return 0;
}