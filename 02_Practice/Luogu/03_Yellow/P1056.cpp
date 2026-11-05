#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
typedef struct Line{
    int num,cnt;
}Line;

Line lleft[MAXN],front[MAXN];/*当前行/列与其右/上一列/行会交头接耳的对数*/
bool cmp(Line x,Line y){
    return x.cnt > y.cnt;
}
int n,m,k,l,d,templ[MAXN],tempf[MAXN];
void init(){
    for(int i = 1; i <= n; i++){
        lleft[i].num = i;
        lleft[i].cnt = -0x3f3f3f3f;
    }
    for(int i = 1; i <= m; i++){
        front[i].num = i;
        front[i].cnt = -0x3f3f3f3f;
    }
}

int main(){
    cin >> n >> m >> k >> l >> d;
    init();
    int nowx1,nowy1,nowx2,nowy2;
    for(int i = 1; i <= d; i++){
        cin >> nowx1 >> nowy1 >> nowx2 >> nowy2;
        if(nowx1 == nowx2){
            if(lleft[min(nowy1,nowy2)].cnt == -0x3f3f3f3f) lleft[min(nowy1,nowy2)].cnt = 0;
            lleft[min(nowy1,nowy2)].cnt++;
        }
        else if(nowy1 == nowy2){
            if(front[min(nowx1,nowx2)].cnt == -0x3f3f3f3f) front[min(nowx1,nowx2)].cnt = 0;
            front[min(nowx1,nowx2)].cnt++;
        }
    }
    sort(lleft + 1,lleft + n + 1,cmp);
    sort(front + 1,front + m + 1,cmp);
    for(int i = 1; i <= l; i++){
        templ[i] = lleft[i].num;
        //cout << lleft[i].num << ' ' << lleft[i].cnt << " | ";
    }
    //cout << "\n";
    for(int i = 1; i <= k; i++){
        tempf[i] = front[i].num;
        //cout << front[i].num << ' ' << front[i].cnt << " | ";
    }
    sort(templ + 1,templ + l + 1);
    sort(tempf + 1,tempf + k + 1);
    for(int i = 1; i <= k; i++){
        cout << tempf[i] << ' ';
    }
    cout << "\n";
    for(int i = 1; i <= l; i++){
        cout << templ[i] << ' ';
    }
    return 0;
}