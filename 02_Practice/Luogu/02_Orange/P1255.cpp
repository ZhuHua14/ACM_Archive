// P1255 数楼梯
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXN = 1e4 + 5;

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
    Bigint operator+(const int a)const;
};

Bigint Bigint::operator+(const Bigint a)const{
    Bigint ans;
    for(int i = 1; i <= max(a.cnt,cnt); i++){
        ans.d[i] += d[i] + a.d[i];
        ans.d[i + 1] += ans.d[i] / 10;
        ans.d[i] = ans.d[i] % 10;
    }
    ans.len();
    return ans;
}

Bigint Bigint::operator+(const int a)const{
    Bigint ans;
    ans.d[1] = a;
	for(int i = 1; i <= cnt; i++){
		ans.d[i] += d[i];
	}
    for(int i = 1; i < MAXN - 1; i++){
        ans.d[i + 1] += ans.d[i] / 10;
        ans.d[i] %= 10;
    }
    ans.len();
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

Bigint f[3];

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> n;
	f[0].d[1] = f[1].d[1] = 1;
	f[0].cnt = f[1].cnt = 1;
	for(int i = 2; i <= n; i++){
		f[i % 3] = f[(i - 1) % 3] + f[(i - 2) % 3];
	}
	print(f[n % 3]);
	return 0;
}
