#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10;
typedef struct Cube{
    int cube[MAXN];
}Cube;
Cube common[9];/*1 2 3 4 5 6 7 8 = 0 A B C D AA AC AD*/
int from[MAXN],to[MAXN];
string str[MAXN] = {"Poland cannot into space!!!","AB","A","B","C","D","AA","AC","AD"};
/*
AAAA == 0 BBBB == 0 CC == 0 DD == 0 
AA == BB == CD == DC
C/D A/B == A/B D/C == B/A C/D  
AB == BA == 0
AAA == B BBB ==  A

0 A B C D AA AC AD
*/
void init(){
    common[1].cube[1] = from[1]; common[1].cube[2] = from[2]; common[1].cube[3] = from[3]; common[1].cube[4] = from[4]; common[1].cube[5] = from[5]; common[1].cube[6] = from[6]; common[1].cube[7] = from[7]; common[1].cube[8] = from[8]; common[1].cube[9] = from[9];
    common[2].cube[1] = from[7]; common[2].cube[2] = from[4]; common[2].cube[3] = from[1]; common[2].cube[4] = from[8]; common[2].cube[5] = from[5]; common[2].cube[6] = from[2]; common[2].cube[7] = from[9]; common[2].cube[8] = from[6]; common[2].cube[9] = from[3];
    common[3].cube[1] = from[3]; common[3].cube[2] = from[6]; common[3].cube[3] = from[9]; common[3].cube[4] = from[2]; common[3].cube[5] = from[5]; common[3].cube[6] = from[8]; common[3].cube[7] = from[1]; common[3].cube[8] = from[4]; common[3].cube[9] = from[7];
    common[4].cube[1] = from[3]; common[4].cube[2] = from[2]; common[4].cube[3] = from[1]; common[4].cube[4] = from[6]; common[4].cube[5] = from[5]; common[4].cube[6] = from[4]; common[4].cube[7] = from[9]; common[4].cube[8] = from[8]; common[4].cube[9] = from[7];
    common[5].cube[1] = from[7]; common[5].cube[2] = from[8]; common[5].cube[3] = from[9]; common[5].cube[4] = from[4]; common[5].cube[5] = from[5]; common[5].cube[6] = from[6]; common[5].cube[7] = from[1]; common[5].cube[8] = from[2]; common[5].cube[9] = from[3];
    common[6].cube[1] = from[9]; common[6].cube[2] = from[8]; common[6].cube[3] = from[7]; common[6].cube[4] = from[6]; common[6].cube[5] = from[5]; common[6].cube[6] = from[4]; common[6].cube[7] = from[3]; common[6].cube[8] = from[2]; common[6].cube[9] = from[1];
    common[7].cube[1] = from[1]; common[7].cube[2] = from[4]; common[7].cube[3] = from[7]; common[7].cube[4] = from[2]; common[7].cube[5] = from[5]; common[7].cube[6] = from[8]; common[7].cube[7] = from[3]; common[7].cube[8] = from[6]; common[7].cube[9] = from[9];
    common[8].cube[1] = from[9]; common[8].cube[2] = from[6]; common[8].cube[3] = from[3]; common[8].cube[4] = from[8]; common[8].cube[5] = from[5]; common[8].cube[6] = from[2]; common[8].cube[7] = from[7]; common[8].cube[8] = from[4]; common[8].cube[9] = from[1];    
}

bool check(int x[],int y[]){
    for(int i = 1; i <= 9; i++){
        if(x[i] != y[i]) return 0;
    }
    return 1;
}
int main(){
    for(int i = 1; i <= 9; i++){
        cin >> from[i];
    }
    for(int i = 1; i <= 9; i++){
        cin >> to[i];
    }
    init();
    for(int i = 1; i <= 8; i++){
        if(check(to,common[i].cube)){
            cout << str[i];
            return 0;
        }
    }
    cout << str[0];
    return 0;
}