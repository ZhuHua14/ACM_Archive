#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string to_p(int x,int p){
    string ret;
    ret.clear();
    int tmp = 0;
    while(x){
        tmp = x % p;
        x /= p;
        if(tmp < 0){
            tmp -= p;
            x += 1;
        }
        // cout << tmp << ' ';
        if(tmp >= 10){
            ret.push_back(tmp % 10 + 'A');
        }
        else{
            ret.push_back(tmp + '0');
        }
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,r;
    cin >> n >> r;
    cout << n << '=' << to_p(n,r) << "(base" << r << ')';
    return 0;
}