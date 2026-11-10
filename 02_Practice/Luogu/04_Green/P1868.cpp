// P1868 饥饿的奶牛
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1.5e5;
const int MAXLEN = 3e6 + 5;

vector<int> range[MAXLEN];

int n,f[MAXLEN];

int main(){
    cin >> n;
    int l,r,maxlen = 0;
    for(int i = 1; i <= n; i++){
        cin >> l >> r;
        maxlen = max(maxlen,r);
        range[r].push_back(l);
    }
    for(int i = 1; i <= maxlen; i++){
        //cout << i << ":";
        f[i] = f[i - 1];
        for(int j = 0; j < range[i].size(); j++){
            f[i] = max(f[i],f[range[i][j] - 1] + (i - range[i][j] + 1));
        }
        //cout << f[i] << ' ';
    }
    cout << f[maxlen] << endl;
    return 0;
}