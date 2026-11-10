// P1540 [NOIP 2010 提高组] 机器翻译
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int m,n,llist[MAXN];
deque<int> unit;
bool find(int word){
	bool flag = 0;
	deque<int> saveunit(unit);
	int nowtop;
	for(auto nowtop:saveunit){
		//nowtop = saveunit.front();
		if(nowtop == word){
			flag = 1;
			break;
		}
		//saveunit.pop();
	} 
	return flag;
}
/*void output(deque<int> w){
	for(auto i:w){
		cout<<i<<" ";
	}
	cout<<endl;
}*/
int main(){
	cin>>m>>n;
	for(int i = 1; i <= n; i++){
		cin>>llist[i];	
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(find(llist[i])){
			continue;
		}
		if(unit.size() >= m){
			while(unit.size() >= m){
				unit.pop_front();
			}
		}
		//cout<<"not find "<<llist[i]<<endl;		
		unit.push_back(llist[i]);
		ans++;
		//output(unit);
	}
	cout<<ans;
	return 0;
}