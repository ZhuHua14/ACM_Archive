#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e2 + 5;

struct Bigint{
    int d[MAXN],cnt = 0;
    
    Bigint() : d(),cnt(0) {}

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

    Bigint operator+(const Bigint& a)const;
    Bigint operator*(const Bigint& a)const;
    Bigint operator*(const int a)const;
};

Bigint Bigint::operator+(const Bigint& a)const{
    Bigint ans;
    for(int i = 1; i <= max(a.cnt,cnt); i++){
        ans.d[i] += d[i] + a.d[i];
        ans.d[i + 1] += ans.d[i] / 10;
        ans.d[i] = ans.d[i] % 10;
    }
    ans.len();
    return ans;
}

Bigint Bigint::operator*(const Bigint& a)const{
    Bigint ans;
    for(int i = 1; i <= MAXN - 1; i++){
        for(int j = 1; j <= i; j++){
            ans.d[i - 1] += a.d[j] * d[i - j];
        }
    }
    for(int i = 1; i < MAXN - 1; i++){
        ans.d[i + 1] += ans.d[i] / 10;
        ans.d[i] %= 10;
    }
    ans.len();
    return ans;
}

Bigint Bigint::operator*(const int a)const{
    Bigint ans;
	for(int i = 1; i <= cnt; i++){
		ans.d[i] += a * d[i];
	}
    for(int i = 1; i < MAXN - 1; i++){
        ans.d[i + 1] += ans.d[i] / 10;
        ans.d[i] %= 10;
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

void print(const Bigint& a){
    if(a.cnt == 0){
        cout << '0';
        return;
    }
    for(int i = a.cnt; i >= 1; i--){
        cout << a.d[i];
    }
}

Bigint a[55],ans;
int n;

//30414093201713378043612608166064768844377641568960512000000000000
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
    cin >> n;
	a[1].d[1] = 1, a[1].cnt = 1;
	ans = ans + a[1];
	for(int i = 2; i <= n; i++){
		a[i] = a[i - 1] * i;
		ans = ans + a[i];
	}
	print(ans);
    
    return 0;
}