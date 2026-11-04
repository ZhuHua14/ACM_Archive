#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
string bling[16] = {
	"RIOI","RiOI","RioI","Rioi","RIoI","RIoi","RIOi","RiOi",
	"rIOI","riOI","rioI","rioi","rIoI","rIoi","rIOi","riOi"
};
string s,t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> s >> t;
	bool flags = 0,flagt = 0;
	for(int i = 0; i < 16 ; i++){
		if(s.find(bling[i]) != s.npos){
			flags = 1;
		}
		if(t.find(bling[i]) != t.npos){
			flagt = 1;
		}
	}
	if(flags && flagt) cout << "Either is ok!";
	else if(flags) cout << s + ' ' + "for sure!";
	else if(flagt) cout << t + ' ' + "for sure!";
	else cout << "Try again!";
	return 0;
}