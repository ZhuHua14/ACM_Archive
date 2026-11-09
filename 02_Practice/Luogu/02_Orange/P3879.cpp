#include<bits/stdc++.h>
using namespace std;

map < string , vector<int> > m;

int n,nowcnt,nowm;
bool bot[1005];
string nowword;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	bool flag = 1;
	for(int i = 1; i <= n; i++){
		cin>>nowcnt;
		for(int j = 1; j <= nowcnt; j++){
			cin>>nowword;
			m[nowword].push_back(i);
		}
	}
	cin>>nowm;
	for(int i = 1; i <= nowm; i++){
		cin>>nowword;
		memset(bot,0,sizeof(bot));
		int nowr = m[nowword].size();
		//cout<<nowr;
		for(int k = 0; k < nowr; k++){
			if(bot[m[nowword][k]] == 0){
				cout<<m[nowword][k]<<' ';	
				bot[m[nowword][k]] = 1;			
			}
		}
		cout<<endl;
	}
	return 0;
}