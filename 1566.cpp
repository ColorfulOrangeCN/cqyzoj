#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1200000;
int main(){
	int d, c;
	while(cin >> d){
		cin >> c;
		int now = 1;
		for(int cnt = 1; cnt < d; ++cnt){
			if(c % 2 == 1){
				now = now * 2;
				c = (c+1)/2;
			} else {
				now = now * 2 + 1;
				c = c / 2;
			}
		}
		cout << now << endl;
	}
	return 0;
}
