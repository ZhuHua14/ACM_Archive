#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e3 + 5;

struct Bigint{
    int d[MAXN],cnt;

    Bigint operator+(const Bigint a)const;
    Bigint operator*(const Bigint b)const;
};

Bigint Bigint::operator+(const Bigint a)const{
    Bigint ans;
    int len = max(a.cnt,cnt);
    for(int i = 1; i <= len; i++){
        int temp = a.d[i] + d[i] + ans.d[i];
        if(temp >= 10){
            ans.d[i + 1]++;
        }
        ans.d[i] = temp % 10;
    }
    if(ans.d[len + 1] != 0){
        ans.cnt = len + 1;
    }
    else ans.cnt = len;
    return ans;
}

Bigint read(){
    Bigint ans;
    string st;
    cin >> st;
    ans.cnt = st.length();
    for(int i = ans.cnt - 1; i >= 0; i--){
        ans.d[ans.cnt - i] = st[i] - '0';
    }
    return ans;
}

void print(Bigint a){
    for(int i = a.cnt; i > 0; i--){
        cout << a.d[i];
    }
}

Bigint a,b;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    a = read();
    b = read();
    print(a + b);   
   return 0;
}