#include <iostream>
using namespace std;
int p, mins = 20000;
void compute(int a, int b, int step){
	if(step >= mins){
		return;
	}
	if(a == p || b == p){
		mins = step;
		return;
	}
	++step;
	//cout << a <<" " << b << endl;
	        compute(a,a+b,step);
		compute(a+b,b,step);
	if(a >= b){
		compute(a-b,b,step);
		compute(a,a-b,step);
	} else {
		compute(b-a,b,step);
		compute(a,b-a,step);
	}
}
int main() {
	cin >> p;
	compute(1,0,0);
	cout << mins << endl;
}
