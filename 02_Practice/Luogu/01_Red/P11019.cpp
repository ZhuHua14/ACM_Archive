// P11019 「LAOI-6」[太阳]] 请使用最新版手机 QQ 体验新功能
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> s;
	int r = s.find(']');
	string name = s.substr(1,r - 1);
	cout << '/';
	for(auto ch : name){
		if(ch >= 'A' && ch <= 'Z'){
			cout << char(ch - 'A' + 'a');
		}
	}
	return 0;
}