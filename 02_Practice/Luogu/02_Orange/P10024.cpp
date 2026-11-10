// P10024 「HCOI-R1」报名人数
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int used[10] = {6,2,5,5,4,5,6,3,7,6};
ll l,r;

int sizeofint(ll x){
    int ans = 0;
    if(x == 0) return 1;
    while(x > 0){
        ans++;
        x /= 10;
    }
    return ans;
}

bool check(ll l,ll r){
    int lsize = sizeofint(l),rsize = sizeofint(r);
    if(lsize != rsize){
        return 0;
    }
    int nowlp,nowrp;
    while(l != r){
        nowlp = l % 10;
        nowrp = r % 10;
        if(nowlp == 9 && nowrp == 0){
            l /= 10;
            r /= 10;
            continue;
        }
        else if(nowlp == 2 && nowrp == 3){
            return 1;
        }
        else return 0;
    }
}

int main(){
    cin >> l >> r;
    if(l == r){
        cout << 1;
        return 0;
    }
    for(ll i = l; i < r; i++){
        if(check(i,i + 1)){
            cout << 2;
            return 0;
        }
    }
    cout << 1;
    return 0;
}