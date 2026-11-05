#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

int n,a[MAXN],bot[MAXN];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int m = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        bot[a[i]]++;
        m = max(m,a[i]);
    }
    int pres = 0;
    for(int i = 1; i <= m; i++){
        if(bot[i] != 0){
            if(pres <= bot[i]){
                pres = bot[i];
            }
        }
    }
    cout << pres << endl;
    return 0;
}
/*
1  2  3
2  2  1

136 2417
8   2
*/