#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e3 + 5;

int T,n,m,k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> T;
	while(T--){
		cin >> n >> m >> k;
		if(k <= min(n,m)){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= m; j++){
					if(i == j && k > 0){
						cout << 'S';
						k--;
					}
					else cout << '.';
				}
				cout << endl;
			}
		}
		else{
			int r = k - min(n,m);
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= m; j++){
					if(r > 0 && i != j){
						cout << 'S';
						r--;
					}
					else if(i == j){
						cout << 'S';
					}
					else{
						cout << '.';
					}
				}
				cout << endl;
			}	
		}
	}
	return 0;
}