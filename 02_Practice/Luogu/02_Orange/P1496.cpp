#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e4 + 5;
struct Line{
	int l,r;
};

Line lines[MAXN];

map<int,int> bot;

int n,cnt,p[MAXN * 2],diff[MAXN * 2],s[MAXN * 2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> lines[i].l >> lines[i].r;
    	p[++cnt] = lines[i].l;
    	p[++cnt] = lines[i].r;
    }
    // cout << cnt << endl;
    sort(p + 1,p + 1 + cnt);
    cnt = unique(p + 1,p + 1 + cnt) - p - 1;
	// cout << cnt << endl;
	// cout << p[cnt] <<endl;
    for(int i = 1; i <= cnt; i++){
    	// cout << p[i] << ' ' << i << '\n';
    	bot.insert({p[i],i});
    }
    // cout << '\n';
    for(int i = 1; i <= n; i++){
    	lines[i].l = bot[lines[i].l];
    	lines[i].r = bot[lines[i].r];
    	// cout << lines[i].l << ' ' << lines[i].r <<'\n';
    }
    for(int i = 1; i <= n; i++){
    	diff[lines[i].l]++;
    	diff[lines[i].r]--;
    }
    for(int i = 1; i <= cnt; i++){
    	s[i] = s[i - 1] + diff[i];
    }
    // for(int i = 1; i <= cnt; i++){
    	// cout << s[i] << ' ';
    // }
    // cout << '\n';
    ll ans = 0;
    int l = 0,r = 0;
    for(int i = 1; i <= cnt; i++){
    	if(s[i] && !s[i - 1]){
    		l = i;
    	}
		if(s[i] && !s[i + 1]){
			r = i + 1;
			// cout << l << ' ' << r << endl;
			// cout << p[l] << ' ' << p[r] << endl;
			ans += p[r] - p[l];
		}
    }
    cout << ans << '\n';
    return 0; 
}

/*
1 2
4 6
3 5

*/