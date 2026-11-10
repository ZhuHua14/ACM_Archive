// P2822 [NOIP 2016 提高组] 组合数问题
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 10;

int t,k,conb[MAXN][MAXN],is0[MAXN][MAXN],presum[MAXN][MAXN];

void init(){
    conb[1][0] = conb[1][1] = 1;
    for(int i = 2; i < MAXN; i++){
        for(int j = 0; j <= i; j++){
            conb[i][j] = (conb[i - 1][j] % k + conb[i - 1][j - 1] % k) % k;
            //conb[i][j] = conb[i - 1][j] + conb[i - 1][j - 1];
            if(conb[i][j] == 0){
                is0[i][j] = 1;
            }
            //cout << is0[i][j] << ' ';
        }
        //cout << '\n';
    }
    //cout << '\n';
    for(int i = 1; i < MAXN; i++){
        for(int j = 0; j < MAXN; j++){
            if(j != 0) presum[i][j] = is0[i][j] + presum[i][j - 1] + presum[i - 1][j] - presum[i - 1][j - 1];
            else presum[i][j] = is0[i][j] + presum[i - 1][j];
            //cout << presum[i][j] << ' ';
        }
        //cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout.tie(0);
    cin >> t >> k;
    init();
    int n,m;
    while(t--){
        cin >> n >> m;
        cout << presum[n][m] << '\n';
    }
    return 0;
}