#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int MOD = 1e7 + 19;

ull hash_table[MOD],f[MOD];
bitset<MOD> flag;

int get_hash(ull x){
    return x % MOD;
}

ull insert(ull x,ull y){
    int h = get_hash(x);
    while(hash_table[h] != x && flag[h] == 1){
        h++;
        if(h >= MOD){
            h = 0;
        }
    }
    flag[h] = 1;
    hash_table[h] = x;
    ull ans = f[h];
    // cout << h << ' ' << hash_table[h] << ' ' << f[h] << '\n';
    f[h] = y;
    return ans;
}

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ull nx,ny,ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> nx >> ny;
        ans += (i * insert(nx,ny));
    }
    cout << ans;
    return 0; 
}