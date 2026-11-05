#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
bool isOnly(int k){
	for(int i=2;i*i<=k;i++){
		//cout<<1;
		//cout << "a" << endl; 
		if(k%i == 0) return 0;
	}
	return 1;
}
bool isBack(int k){
	int a[12],flag = 0,num=k;
	while(num != 0){
		//cout<<2;
		//cout << "b" <<endl;
		a[flag] = num % 10;
		num /= 10;
		//cout<<num<<endl;
		flag++;
	}
	//for(int i=0;i<flag;i++) cout<<a[i];
	for(int i=0;i<flag;i++){
		//cout<<3;
		//cout << "c" <<endl;
		if(a[i] != a[flag-i-1]) /*cout<<a[i]<<" "<<a[flag-i-1]<<' '<<((a[i] != a[flag-i-1])? 'Y':'N')<<endl;*/return 0;
	}
	return 1;
}
bool isDouble(int k){
	int a[12],flag=0,num=k;
	while(num != 0){
		//cout<<2;
		//cout << "b" <<endl;
		a[flag] = num % 10;
		num /= 10;
		//cout<<num<<endl;
		flag++;
	}
	return flag%2==0;
}
int up,down,mapp[MAXN],cnt=0;
int main(){
	cin>>up>>down;
	if(up%2 == 0) up++;
	for(int ans = up;ans <= down;ans += 2){
		//cout<<4;
		//cout<<"d"<<endl;
		//cout<<ans<<endl;
		if(ans == 2 || ans == 11) {
			mapp[cnt] = ans;
			//cout<<ans<<endl;
			cnt++;
			continue;
		}
		if(!isDouble(ans)){		
		if(isBack(ans)){
		if(isOnly(ans)){
				mapp[cnt] = ans;
				cnt++;
				//cout<<ans<<endl;
				//cout<<"A";
		}
		}
		}

	}
	//cout<<cnt<<endl;
	for(int i = 0;i < cnt;i++){
		//cout<<5;
		//cout<<"f"<<endl;
		cout<<mapp[i]<<endl;
	}
	return 0;
} 