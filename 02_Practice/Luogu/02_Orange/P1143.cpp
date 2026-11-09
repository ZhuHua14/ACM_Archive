#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 55;

int a[MAXN];

int to10(string num,int p){
    int ret = 0;
    for(auto ch : num){
        ret *= p;
        if(ch >= '0' && ch <= '9'){
            ret += ch - '0';
        }
        else{
            ret += ch - 'A' + 10;
        }
        // cout << ch << ' ' << ret << '\n';
    }
    return ret;
}

string to_p(int x,int p){
    string ret;
    ret.clear();
    int tmp = 0;
    while(x){
        tmp = x % p;
        if(tmp >= 10){
            ret.push_back(tmp % 10 + 'A');
        }
        else{
            ret.push_back(tmp + '0');
        }
        x /= p;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

string p_to_p(string num,int pi,int po){
    int num_10 = to10(num,pi);
    // cerr << num_10 << '\n';
    return to_p(num_10,po);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    string num;
    cin >> n >> num >> m;
    cout << p_to_p(num,n,m);
    return 0;
}