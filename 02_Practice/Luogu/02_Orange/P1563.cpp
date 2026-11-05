#include<bits/stdc++.h>
using namespace std;
int n,m;
struct people{
	int chaoxiang;
	string zhiye;
}cir[100010];
int shunshizhen(int place,int placecount){
	int end;
	end=place-placecount;
	if(end>=1)	return end;
	return n+end;
}
int nishizhen(int place,int placecount){
	int end;
	end=place+placecount;
	if(end<=n)	return end;
	return end-n;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>cir[i].chaoxiang>>cir[i].zhiye;
    }
    int ans=1,count,fangxiang;
    for(int j=1;j<=m;j++){
    	cin>>fangxiang>>count;
    	if(fangxiang^cir[ans].chaoxiang==0){
			//cout<<"shunshizhen"<<endl;
			ans=shunshizhen(ans,count);
		}
    	else if(fangxiang^cir[ans].chaoxiang==1){
			//cout<<"nishizhen"<<endl;
			ans=nishizhen(ans,count); 
    	}
		//cout<<ans<<endl;
    }
	cout<<cir[ans].zhiye;
	return 0;
}