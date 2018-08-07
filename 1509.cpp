#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
	int N;
	cin >> N;
	stack<int> s;
	string str;
	for(int i = 0; i < N; ++i){
		cin >> str;
		if(str == "push"){
			int v;
			cin >> v;
			s.push(v);
		} else if(str == "top"){
			if(s.empty()){
				cout << "error" << endl;
			} else {
				cout << s.top() << endl;
			}
		} else if(str == "pop"){
			if(s.empty()){
				cout << "error" << endl;
			} else {
				s.pop();
			}
		} else if(str == "empty"){
			if(s.empty()){
				cout << "empty" << endl;
			} else {
					cout << "not empty" << endl;
			}
		} else if(str == "clear"){
			s = stack<int>();
		}
	}
}
