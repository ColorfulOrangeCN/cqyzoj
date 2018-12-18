#include <iostream>
using namespace std;

int n,m,mins = 26;

void convert(int now, int step){
	if(step > mins){
		return;
	}
	if(now == m && mins > step){
		mins = step;
	}
	++step;
	convert(3*now,step);
	convert(now/2,step);
}

int main(){
	cin >> n >> m;
	convert(n,0);
	if(mins > 25){
		cout << "No solution!" << endl;
	} else
		cout << mins << endl;
	return 0;
}
