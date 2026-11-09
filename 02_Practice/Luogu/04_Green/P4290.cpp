#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 205;

bool f[MAXN][MAXN][4],can[4][4][4];
ll wing[5];
char ch[MAXN];

int toint(char x){
	if(x == 'W') return 0;
	if(x == 'I') return 1;
	if(x == 'N') return 2;
	else return 3;
}

char tochar(int x){
	if(x == 0) return 'W';
	if(x == 1) return 'I';
	if(x == 2) return 'N';
	else return 'G';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i = 0; i < 4; i++){
		cin >> wing[i];
	}
	char nowin1,nowin2;
	for(int i = 0; i < 4; i++){
		for(int j = 1; j <= wing[i]; j++){
			cin >> nowin1 >> nowin2;
			can[toint(nowin1)][toint(nowin2)][i] = 1;			
		}
	}
	cin >> (ch + 1);
	ll n = strlen(ch + 1);
	for(int i = 1; i <= n; i++){
		f[i][i][toint(ch[i])] = 1;
	}
	for(int len = 2; len <= n; len++){
		for(int l = 1; l + len - 1 <= n; l++){
			int r = l + len - 1;
			for(int nowp = 0; nowp < 4; nowp++){
				for(int k = l; k <= r - 1; k++){
					for(int lpos = 0; lpos < 4; lpos++){
						for(int rpos = 0; rpos < 4; rpos++){
							if(can[lpos][rpos][nowp] == 1) f[l][r][nowp] |= f[l][k][lpos] && f[k + 1][r][rpos];
						}
					}
				}				
			}
		}
	}
	bool flag = 0;
	for(int i = 0; i < 4; i++){
		if(f[1][n][i] == 1){
			flag = 1;
			cout << tochar(i);			
		}
	}
	if(!flag) cout << "The name is wrong!" << endl;
	cout << endl;
	return 0;
}
