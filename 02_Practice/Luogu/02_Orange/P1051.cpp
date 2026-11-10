// P1051 [NOIP 2005 提高组] 谁拿了最多奖学金
#include<bits/stdc++.h>
using namespace std;

struct Student{
	string name;
	int score,classscore,lunwen,money;
	char western,banganbu;
}student[105],ansmax;

int main(){
	int n,ans;
	cin >> n;
	for (int i = 1;i <= n; i++){
		cin >> student[i].name >> student[i].score >> student[i].classscore >> student[i].banganbu >> student[i].western >> student[i].lunwen;
		if (student[i].score > 80 && student[i].lunwen >= 1){
			student[i].money += 8000;
		}
		if (student[i].score > 85 && student[i].classscore > 80){
			student[i].money += 4000;
		}
		if (student[i].score > 90 ){
			student[i].money += 2000;
		}
		if (student[i].score > 85 && student[i].western == 'Y'){
			student[i].money += 1000;
		}
		if (student[i].classscore > 80 && student[i].banganbu == 'Y'){
			student[i].money += 850;
		}
		ans += student[i].money;
		if (student[i].money > ansmax.money){
			ansmax.name = student[i].name;
			ansmax.money = student[i].money;
		}
	}
	cout << ansmax.name << endl << ansmax.money << endl << ans;
	return 0;
}