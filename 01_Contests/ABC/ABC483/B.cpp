//B - Flip Card Stack
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 105;

int n, q, a[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        a[i] = i;
    }
    int k;
    while(q--){
        cin >> k;
        for(int i = 1; i * 2 <= k; i++){
            swap(a[i], a[k - i + 1]);
        }
        for(int i = 1; i <= k; i++){
            a[i] = -a[i];
        }
    }
    for(int i = 1; i <= n; i++){
        cout << a[i] << '\n';
    }
    return 0;
}


/* 1  2  3  4  5
  -3 -2 -1  4  5
  -5 -4  1  2  3

*/