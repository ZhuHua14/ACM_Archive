#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e3 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
char a[MAXN],b[MAXN];
ll f[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> (a + 1) >> (b + 1);
    ll len_a = strlen(a + 1),len_b = strlen(b + 1);
    memset(f,0x3f,sizeof(f));
    for(int i = 0; i <= len_a; i++){
        for(int j = 0; j <= len_b; j++){
            if(j == 0){
                f[i][j] = i;
            }
            if(i == 0){
                f[i][j] = j;
            }
            else if(a[i] == b[j]){
                f[i][j] = f[i - 1][j - 1];
            }
            else{
                f[i][j] = min(f[i - 1][j],min(f[i - 1][j - 1],f[i][j - 1])) + 1;
            }
        }
    }
    cout << f[len_a][len_b] << endl;
    return 0;
}