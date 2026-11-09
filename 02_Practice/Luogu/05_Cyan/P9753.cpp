#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e6 + 5;

char ch[MAXN];
ll f[MAXN],n,ans,pre[MAXN],nowp[26];

int toint(char c){
	return c - 'a';	
}

bool findpre(int pos){
	int tmp = pos;
	while(pos > 0 && ch[pos - 1] != ch[tmp]){
		pos = pre[pos - 1];
	}
	pre[tmp] = pos - 1;
	return (pre[tmp] < 0? 0:1);
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cin >> (ch + 1);
	for(int i = 1; i <= n; i++){
		ll nowint = toint(ch[i]);
		pre[i] = nowp[nowint];
		nowp[nowint] = i;
	}
	for(int i = 1; i <= n; i++){
		if(findpre(i)) f[i] = f[pre[i] - 1] + 1;
		ans += f[i];
	}
	cout << ans << endl;
	return 0;
}