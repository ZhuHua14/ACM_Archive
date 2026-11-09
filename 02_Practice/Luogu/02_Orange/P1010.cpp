#include<bits/stdc++.h>
//#include<windows.h>
using namespace std;
void output(int k){
	int nowlog = 0;
	while(k != 0){
		nowlog = (int)(log2(k));
		if(nowlog == 1) {
			cout<<"2";
			//return;
		}
		else if(nowlog == 0){
			cout<<"2(0)";
			return;
		} 
		else{		
			cout<<"2(";
			output(nowlog);
			//Sleep(1000);
			cout<<")";
		}
		//cout<<nowlog<<" "<<k<<"\n";
		k -= pow(2,nowlog);
		if(k != 0) cout<<"+"; 
	}
}
//2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
//2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
int n;
int main(){
	cin>>n;
	output(n);
	return 0;
} 