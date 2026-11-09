#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef struct Node{
	int data;
	int pre,next;
}Node;

Node create(int data,int pre,int next){
	Node ans;
	ans.data = data;
	ans.next = next;
	ans.pre = pre;
	return ans;
}

Node node[MAXN];
int iindex[MAXN],cnt = 0;
void insert(int k,int nowpre,int nownext){
    node[++cnt] = create(k,nowpre,nownext);
    if(nownext != 0x3f3f3f3f) node[nownext].pre = cnt;
    node[nowpre].next = cnt;
    iindex[k] = cnt;
}

void erase(int k){
    int nowp = iindex[k];
    int nowpre = node[nowp].pre,nownext = node[nowp].next;
    node[nowpre].next = nownext;
    if(nownext != 0x3f3f3f3f) node[nownext].pre = nowpre;
    iindex[k] = 0;
}
int n,m;

int main(){
    cin >> n;
    iindex[0] = 0;
    insert(1,0,0x3f3f3f3f);
    int opt,nowin;
    for(int i = 2; i <= n; i++){
        cin >> nowin >> opt;
        int nowp = iindex[nowin];
        if(opt == 0){
            insert(i,node[nowp].pre,nowp);
        }
        else{            
            insert(i,nowp,node[nowp].next);
        }
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> nowin;
        if(iindex[nowin] != 0) erase(nowin);
    }
    int i = node[0].next;
    while(i != 0 && i != 0x3f3f3f3f){
        cout << node[i].data << ' ';
        i = node[i].next;
    }
    return 0;
}