#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e3 + 5;
ll p[MAXN],a[MAXN];
ll x,cnt,pos;
bool isPrime(ll x){
    for(int i = 2; i * i < x; i++){
        if(x % i == 0) return 0;
    }
    return 1;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> x;
    ll pre = 2;
    bool flag = 0;
    ll temp = x;
    while(x > 1){
        if(pre * pre >= temp){
            p[++pos] = x;
            a[pos]++;
            cnt++;
            break;
        }
        else if(isPrime(pre) && x % pre == 0){
            // cout << pre << ' ';
            p[pos] = pre;
            while(x % pre == 0){
                x /= pre;
                cnt++;
                a[pos]++;
            }
            if(a[pos] > 1) flag = 1;
            // cout << pos << ' ' << a[pos] << endl;
            pos++;
        }
        pre++;
    }
    // cout << pos << endl;
    if(pos == 1) cout << temp;
    else if(cnt % 2 == 0 || flag) cout << 1;
    else cout << p[0];
    return 0;
}