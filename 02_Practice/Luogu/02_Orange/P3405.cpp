// P3405 [USACO16DEC] Cities and States S
#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e6 - 17;
const int BASE = 26;
map<int/*hash(city)*/,int/*cnt*/> m[MOD + 2]/*hash(state)*/;

int n;

int Hash(string s){
	int ans;
	for(int i = 0; i < s.size(); i++){
		ans = (ans * BASE + (int)(s[i])) % MOD;
	}
	return ans;
}

string nowstate,nowcity;

int main(){
	cin>>n;
	int ans = 0,nowshash,nowchash;
	for(int i = 1; i <= n; i++){
		cin>>nowcity>>nowstate;
		nowcity = nowcity.substr(0,2);
		nowshash = Hash(nowstate);
		nowchash = Hash(nowcity);
		ans += m[nowshash][nowchash];
		if(nowchash == nowshash) ans -= m[nowchash][nowshash];
		m[nowchash][nowshash]++;
	}
	cout<<ans;
	return 0;
}