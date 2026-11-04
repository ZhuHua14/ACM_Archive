#include<bits/stdc++.h>
using namespace std;

int main(){
	long long di,zhi;
	cin>>di>>zhi;
	long long ans=1;
	for(int i=1;i<=zhi;i++){
		ans*=di;
		if(di==1){
			cout<<1;
			return 0;
		}
		else if(ans>1000000000){
			cout<<-1;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}