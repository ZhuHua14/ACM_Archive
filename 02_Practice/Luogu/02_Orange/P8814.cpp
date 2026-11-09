#include<bits/stdc++.h>
using namespace std;
long long fp(long long n,long long d,long long e){
    return (n-e*d+2+sqrt((n-e*d+2)*(n-e*d+2)-4*n))/2;
}
long long fq(long long n,long long d,long long e){
    return (n-e*d+2-sqrt((n-e*d+2)*(n-e*d+2)-4*n))/2;
}
long long p[100005],q[100005];
bool flag[100005];
int main(){
    //freopen("decode.in",r,stdin);
    //freopen("decode.out",w,stdout);
    int k;
    cin>>k;
    long long inn,ine,ind;
    for(int i=1;i<=k;i++){
        cin>>inn>>ind>>ine;
        //long long n = sqrt((inn-ine*ind+2)*(inn-ine*ind+2)-4*inn);
        long long m = (inn-ine*ind+2)*(inn-ine*ind+2)-4*inn;
        if (m<0){
            flag[i] = 1;
            //cout<<"test "<<(long long)sqrt((inn-ine*ind+2)*(inn-ine*ind+2)-4*inn)<<"    "<<sqrt((inn-ine*ind+2)*(inn-ine*ind+2)-4*inn)<<endl;
            continue;
        }
        p[i]=1.0*(( inn-ine*ind+2)-sqrt(m))/2;
        q[i]=1.0*(( inn-ine*ind+2)+sqrt(m))/2;
        if(p[i]<0||q[i]<0||p[i]*q[i]!=inn||ine*ind!=(p[i]-1)*(q[i]-1)+1){
            //cout<<"tee  "<<p[i]<<"  "<<q[i]<<"   "<<p[i]*q[i]<<endl;
            flag[i] = 1;
        }
    }
    for(int j=1;j<=k;j++){
        if(flag[j]) {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<min(p[j],q[j])<<" "<<max(p[j],q[j])<<endl;
    }
    //fclose("decode.in");
    //fclose("decode.out");
    return 0;
}