#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;

signed main(){
    cin >> n;
    int nowx1,nowx2,nowy1,nowy2;
    int x1 = 1e9,x2 = -1e9 ,y1 = 1e9,y2 = -1e9;
    for(int i = 1; i <= n; i++){
        cin >> nowx1 >> nowy1 >> nowx2 >> nowy2;
        x1 = min(x1,min(nowx1,nowx2));
        x2 = max(x2,max(nowx1,nowx2));
        y1 = min(y1,min(nowy1,nowy2));
        y2 = max(y2,max(nowy1,nowy2));
    }
    cout << abs(x2 - x1) * abs(y2 - y1) << endl;
    return 0;
}