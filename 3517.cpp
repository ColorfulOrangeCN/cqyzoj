#include <iostream>
using namespace std;
const int maxn = 100005;
char str[maxn], *top = str;
int main(){
	int n;
	cin >> n;
	char c;
	int tmp;
	for(int i = 0; i < n; ++i){
		cin >> c;
		if(c == 'T'){
			cin >> c;
			*(top++) = c;
		} else if(c == 'Q'){
		        cin >> tmp;
			cout << str[tmp-1] << endl;
		} else {
			cin >> tmp;
			top -= tmp;
		}
	}
}
