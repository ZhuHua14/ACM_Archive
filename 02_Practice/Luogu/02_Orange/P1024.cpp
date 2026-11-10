// P1024 [NOIP 2001 提高组] 一元三次方程求解
#include<bits/stdc++.h>
using namespace std;
double x[10]={111.0,111.0,111.0,111.0,111.0,111.0,111.0,111.0,111.0,111.0};
double a,b,c,d;
double e=1e-4;
double f(double xx){
	return a * xx * xx * xx + b * xx * xx + c * xx + d;
}
int now;
int main(){
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	for(int i = -100;i <= 100;i++){
		double nowi = i,nexti = i + 1,mid;
		//printf("%f %f %f %f\n",nowi,nexti,f(nowi),f(nexti));
			if(fabs(f(nowi)) < e){
				x[now] = nowi;
				now++;
			}
			else if(fabs(f(nexti)) < e){
				continue;
			}
			else if(f(nexti) * f(nowi) < 0.0){
				mid = (nowi + nexti) / 2;
				//printf("\n%f %f %f\n",mid,nowi,nexti);
				while(fabs(f(nowi) - f(nexti))> e){
					//printf("\n%f %f %f\n",mid,nowi,nexti);
					mid = (nowi + nexti) / 2;
					//printf("%f ",mid);
					if(f(mid) * f(nowi) > 0.0) nowi = mid;
					else nexti = mid;
				}
				//printf("\n%f \n",nexti);
				x[now] = nexti;
				now++;
			}
	}
	for(int i = 0; i < 3;i++){
		printf("%.2f ",x[i]);
	}
	return 0;
}