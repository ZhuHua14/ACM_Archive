// P1854 [IOI 1999] 花店橱窗布置
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 105;

ll n,v;
ll a[MAXN][MAXN],f[MAXN][MAXN];
struct Node{
	int ans[MAXN];
};
Node node[MAXN][MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> v;
    memset(f,-0x3f,sizeof(f));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= v; j++){
            cin >> a[i][j];
        }
    }
    //ll ans = -0x3f3f3f3f3f3f3f3f;
    ll nowans = 0x3f3f3f3f3f3f3f3f;
    for(int i = 0; i <= n; i++){
        ll nowans = 0x3f3f3f3f3f3f3f3f;
        for(int j = i; j <= v; j++){
            if(i == 0){
                f[i][j] = 0;
                continue;
            }
            if(f[i][j - 1] > f[i - 1][j - 1] + a[i][j]){
            	node[i][j] = node[i][j - 1];
                f[i][j] = f[i][j - 1];
            }
            else{
                node[i][j] = node[i - 1][j - 1];
                node[i][j].ans[i] = j;
                f[i][j] = f[i - 1][j - 1] + a[i][j];
            }
            //if(i == n) ans = max(f[i][j],ans);
        }
    }
    cout << f[n][v] << endl;
    for(int i = 1; i <= n; i++){
        cout << node[n][v].ans[i] << ' ';
    }
    cout << endl;
    return 0;
}