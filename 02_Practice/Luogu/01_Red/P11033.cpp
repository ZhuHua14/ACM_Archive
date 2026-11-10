// P11033 【MX-X3-T0】「RiOI-4」宾果游戏
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

bool cu[6][6];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	for(int i = 1; i <= 5; i++){
		for(int j = 1; j <= 5; j++){
			cin >> cu[i][j];
		}
	}
	bool flag = 0;
	for(int i = 1; i <= 5; i++){
		if(cu[i][1] && cu[i][2] && cu[i][3] && cu[i][4] && cu[i][5]){
			cout << "Yes" << endl;
			return 0;
		}
	}
	for(int i = 1; i <= 5; i++){
		if(cu[1][i] && cu[2][i] && cu[3][i] && cu[4][i] && cu[5][i]){
			cout << "Yes" << endl;
			return 0;
		}
	}
	if(cu[1][1] && cu[2][2] && cu[3][3] && cu[4][4] && cu[5][5]){
		cout << "Yes" << endl;
		return 0;
	}
	if(cu[1][5] && cu[2][4] && cu[3][3] && cu[4][2] && cu[5][1]){
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
	return 0;
}