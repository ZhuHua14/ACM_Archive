#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 105;

bool f[MAXN][MAXN];
ll n;

void floyd(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                f[i][j] = f[i][j] || (f[i][k] && f[k][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> f[i][j];
        }
    }
    floyd();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << f[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}