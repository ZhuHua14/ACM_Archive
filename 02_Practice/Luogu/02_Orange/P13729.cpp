#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 14;

ll T,a,b;
int maxp;
ll pow10[MAXN] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000};
ll long1[MAXN] = {1,11,111,1111,11111,111111,1111111,11111111,111111111,1111111111,11111111111,111111111111,1111111111111};

bool check(ll a){
    if(a == 0) return 0;
    int i = 0;
    bool flag = 1;
    while(a != 0){
        if((a % 10) % 2 == 0){
            flag = 0;
            maxp = i;
        }
        a /= 10;
        i++;
    }
    return flag;
}

int main(){
    // freopen("odd.in","r",stdin);
    // freopen("odd.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        cin >> a;
        maxp = 0,b = 0;
        if(check(a)){
            cout << 0 << '\n';
            continue;
        }
        if(a == 0){
            cout << 1 << '\n';
            continue;
        }
        b += pow10[maxp] - (a % pow10[maxp]);
        b += long1[maxp - 1];
        cout << b << '\n';
    }
    cout << flush;
    // fclose(stdin);
    // fclose(stdout);
   return 0;
}