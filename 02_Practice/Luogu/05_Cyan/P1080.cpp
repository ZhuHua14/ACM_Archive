// P1080 [NOIP 2012 提高组] 国王游戏
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int LEN = 5e3 + 5;
const int MAXN = 1e3 + 5;

struct Bigint{
    int d[LEN],cnt;
    Bigint(){
        memset(d,0,sizeof(d));
        cnt = 0;
    }
    Bigint(int x){
    	memset(d,0,sizeof(d));
        int i = 1;
        while(x != 0){
        	d[i] = x % 10;
        	x /= 10;
        	i++;
        }
        len();
    }
    int len(){
        if(cnt != 0) return cnt;
        else{
            for(int i = LEN - 1; i >= 1; i--){
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
    Bigint operator/(const int a)const;
	bool operator>(const Bigint a)const;
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
    for(int i = 1; i < LEN; i++){
        for(int j = 1; j <= i; j++){
            // cout << i << ' '<< j<< ' ';
            ans.d[i - 1] += a.d[j] * d[i - j];
        }
    }
    for(int i = 1; i < LEN - 1; i++){
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
    for(int i = cnt + 1; i <= LEN; i++){
        int temp = ans.d[i];
        ans.d[i] = temp % 10;
        ans.d[i + 1] = temp / 10;
    }
    ans.len();
    return ans;
}

Bigint Bigint::operator/(const int a)const{
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

bool Bigint::operator>(const Bigint a) const{
	if(cnt > a.cnt) return 1;
	else if(cnt < a.cnt) return 0;
	else{
		for(int i = cnt; i >= 1; i--){
			if(d[i] > a.d[i]){
				return 1;
			}
			else if(d[i] < a.d[i]){
				return 0;
			}
		}
	}
	return 0;
}

Bigint max(Bigint a,Bigint b){
	return (a > b)? a : b;
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

struct Node{
	int a, b;
};

bool cmp(Node x, Node y){
	return max(y.b, x.a * x.b) < max(x.a, y.a * y.b);
}


Node node[MAXN];

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i <= n; i++){
    	cin >> node[i].a >> node[i].b;
    }
    sort(node + 1, node + n + 1, cmp);
	Bigint premul,ans;
	premul = node[0].a;
    for(int i = 1; i <= n; i++){
    	ans = max(ans,premul / node[i].b);
    	premul = premul * node[i].a;
    }
    print(ans);
   return 0;
}