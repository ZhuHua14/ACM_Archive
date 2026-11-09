#include<bits/stdc++.h>
using namespace std;
int n,a[105];
int main(){
	cin>>n;
	for(int i=n;i>=0;i--){
		cin>>a[i];
	}
	for(int i=n;i>=0;i--){
		if(a[i] == 0) continue;
		else if(a[i] > 0 && i != n){		
		    cout<<"+";
		}
		if(abs(a[i]) == 1){
			if(i == 0){
				cout<<a[i];
			}
			else if(a[i] == -1){
				cout<<"-";
			}
		}
		else if(a[i] != 1 || i == 0) cout<<a[i];
		if(i == 0) continue;
		else if(i == 1){
			cout<<"x";
			continue;
		}
		cout<<"x^"<<i;
	}
	return 0;
}