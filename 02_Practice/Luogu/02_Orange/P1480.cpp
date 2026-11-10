// P1480 A/B Problem（高精度除法Ⅰ）
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e3 + 5;

struct Bigint{
    int d[MAXN],cnt;
    Bigint(){
        memset(d,0,sizeof(d));
        cnt = 0;
    }
    int len(){
        if(cnt != 0) return cnt;
        else{
            for(int i = MAXN - 1; i >= 1; i--){
                if(d[i] != 0){
                    cnt = i;
                    return cnt;
                }
            }
        }
        return 0;
    }
    Bigint operator+(const Bigint a)const;
    Bigint operator*(const Bigint b)const;
    Bigint operator*(const int a)const;
    Bigint operator/(const ll a)const;
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
    ans.len();
    return ans;
}

Bigint Bigint::operator*(const Bigint a)const{
    Bigint ans;
    for(int i = 1; i < MAXN; i++){
        for(int j = 1; j <= i; j++){
            // cout << i << ' '<< j<< ' ';
            ans.d[i - 1] += a.d[j] * d[i - j];
        }
    }
    for(int i = 1; i < MAXN - 1; i++){
        ans.d[i + 1] += ans.d[i] / 10;
        ans.d[i] %= 10;
        // cout << 1;
    }
    ans.len();
    return ans;
}

Bigint Bigint::operator*(const int a)const{
    Bigint ans;
    for(int i = 1; i <= cnt; i++){
        int temp = d[i] * a + ans.d[i];
        ans.d[i] = temp % 10;
        ans.d[i + 1] = temp / 10;
    }
    for(int i = cnt + 1; i <= MAXN; i++){
        int temp = ans.d[i];
        ans.d[i] = temp % 10;
        ans.d[i + 1] = temp / 10;
    }
    ans.len();
    return ans;
}

Bigint Bigint::operator/(const ll a)const{
    Bigint ans;
    ll temp = 0;
    for(int i = cnt; i >= 1; i--){
        temp *= 10;
        temp += d[i];
        ans.d[i] = temp / a;
        temp -= ans.d[i] * a;
    }
    ans.len();
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
    if(a.cnt == 0){
        cout << '0';
        return;
    }
    for(int i = a.cnt; i >= 1; i--){
        cout << a.d[i];
    }
}

Bigint a,b;

ll c;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    a = read();
    // b = read();
    // cin >> b;
    cin >> c;
    print(a / c); 
   return 0;
}