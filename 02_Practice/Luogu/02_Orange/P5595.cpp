// P5595 【XR-4】歌唱比赛
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
string res;
int ansx[MAXN],ansy[MAXN];
int main(){
    cin >> res;
    for(int i = res.size() - 1; i >= 0; i--){
        if(res[i] == 'Z' && res[i + 1] != 'X' && res[i + 1] != 'Y'){
            ansx[i] = 0;
            ansy[i] = 0;
        }
        else if(res[i] == 'X'){
            ansx[i] = 1;
            ansy[i] = 0;
        }
        else if(res[i] == 'Y'){
            ansx[i] = 0;
            ansy[i] = 1;
        }
        else{
            cout << -1;
            return 0;
        }
    }
    for(int i = 0; i < res.size(); i++){
        cout << ansx[i];
    }
    cout << "\n";
    for(int i = 0; i < res.size(); i++){
        cout << ansy[i];
    }
    return 0;
}