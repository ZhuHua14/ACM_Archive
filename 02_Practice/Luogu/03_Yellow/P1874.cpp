// P1874 快速求和
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXLEN = 45;
const int MAXN = 1e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
char str[MAXLEN];
ll n,num[MAXLEN][MAXLEN],f[MAXLEN][MAXN];

//f[i][n] -> 在前i位凑出n所需的最小加号数量
//f[i][n] = min(j belongs to [1,i]) f[j][n - num[j][i]] + 1;
//预处理num[l][r]为第l到r位的数字
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> (str + 1);
    cin >> n;
    int len = strlen(str + 1);
    memset(f,0x3f,sizeof(f));
    for(int i = 1; i <= len; i++){
        num[i][i] = ll(str[i] - '0');
        for(int j = i + 1; j <= len; j++){
            num[i][j] = (num[i][j - 1] * 10) + ll(str[j] - '0');
            //cout << i << ' ' << j << ' ' << num[i][j] << endl;
        }
    }
    f[0][0] = -1;
    for(int i = 1; i <= len; i++){
        for(int j = 0; j <= n; j++){
            for(int k = i; k >= 1 && num[k][i] <= n; k--){
                if(j - num[k][i] >= 0) f[i][j] = min(f[i][j],f[k - 1][j - num[k][i]] + 1);
            } 
        }
    }
    /*for(int i = 1; i <= len; i++){
        for(int j = 0; j <= n; j++){
            cout << (f[i][j] == INF? -1:f[i][j]) << ' ';
        }
        cout << endl;
    }*/
    cout << (f[len][n] > len? -1:f[len][n]) << endl;
    return 0;
}

/*
HACK:
000300000000000000000000000000
3

1

000000000000000000000000003000 
3

1

000300000000000000000000003000 
6

2
*/