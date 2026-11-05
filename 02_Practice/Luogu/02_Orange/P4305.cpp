#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5e4 + 5;
const int MOD = 1e5 + 7;

int Hash(int x){
	return (x % MOD + MOD) % MOD;
}

int t,n,nowdata,nowhash;
int cnt,prehash[MOD + 2];

vector<int> llist[MOD + 2];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> t;
	bool flag = 1;
	int maxhash = -1;
	for(int i = 1; i <= t; i++){
		cin >> n;
		flag = 1;
		for(int j = 1; j <= n; j++){
			cin >> nowdata;
			flag = 1;
			nowhash = Hash(nowdata);
			maxhash = max(nowhash,maxhash);
			for(int k = 0; k < llist[nowhash].size(); k++){
				if(llist[nowhash][k] == nowdata){
					flag = 0;
					break;
				}
			}
			if(flag) {
				cout<<nowdata<<' ';
				llist[nowhash].push_back(nowdata);
			}
		}
		cout << endl;
		for(int i = 0; i <= maxhash; i++){
			if(!llist[i].empty()) llist[i].clear();
		}
	}
	return 0;
}