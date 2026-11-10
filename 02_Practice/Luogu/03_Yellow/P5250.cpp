// P5250 【深基17.例5】木材仓库
#include<bits/stdc++.h>
using namespace std;

set <int> s;

void incert(int len){
	if(!s.insert(len).second){
		cout<<"Already Exist\n";
		return;
	}
	s.insert(len);
	return;
}

void erase(int len){
	if(s.empty()){
		cout<<"Empty\n";
		return;
	}
	else if(s.find(len) != s.end()){
		cout<<len<<endl;
		s.erase(len);
		return;
	}
	else{
		auto itl = s.lower_bound(len) , itr = s.upper_bound(len);
		int ans;
		if(itl != s.begin()) itl--;
		if(itr == s.end()) ans = *itl;
		else ans = (len - (*itl)) <= ((*itr) - len)? (*itl):(*itr); 
		cout<<ans<<endl;
		s.erase(ans);
		return;
	}
}

int n;

int main(){
	cin>>n;
	int op,l;
	for(int i = 1; i <= n; i++){
		cin>>op>>l;
		switch(op){
			case 1:{
				incert(l);
				break;
			}
			case 2:{
				erase(l);
				break;
			}
		}
	}
	return 0;
}