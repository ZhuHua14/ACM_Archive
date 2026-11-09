#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
const int MOD = 1e5 + 7;
const int BASE = 256;

string nowin;

vector <string> llist[MOD];

int Hash(string s){
	int ans;
	for(int i = 0; i < s.size(); i++){
		ans = (ans * BASE + (int)(s[i])) % MOD;
	}
	return ans;
}

int n;

int main(){
	cin>>n;
	int nowhash,nowans = n;
	for(int i = 1; i <= n; i++){
		cin>>nowin;
		bool flag = 1;
		nowhash = Hash(nowin);
		for(int j = 0; j < llist[nowhash].size(); j++){
			if(nowin == llist[nowhash][j]){
				nowans--;
				flag = 0;
				break;
			}
		}
		if(flag) llist[nowhash].push_back(nowin);
	}
	cout<<nowans;
	return 0;
}          