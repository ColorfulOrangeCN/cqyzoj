#include <iostream>
#include <string>
#include <cctype>
#include <stack>
using namespace std;

int js(char opert, int a, int b){
	switch(opert){
		case '+':
			return a+b;
			break;
		case '-':
			return a-b;
			break;
		case '*':
			return a*b;
			break;
	};
	return 0;
}

void opert(const string& s){
	stack<char> opers;
	stack<int> digits;
	int t = 0;
	bool check = false;
	for(int i = 0; i < s.size(); ++i){
		if(isdigit(s[i])){
			t *= 10;
			t += s[i];
			check = true;
		} else {
			if((i == 0 || !isdigit(s[i-1])) && s[i] != '(' && s[i] != ')'){
				digits.push(0);
			}
			if(check){
				digits.push(t);
				t = 0;
				check = false;
			}
			switch(s[i]){
				case '+':
					if(opers.empty() || opers.top() != '*'){
						char opert = opers.top();
						opers.pop();
						int a,b;
						a = digits.top(),digits.pop();
						b = digits.top(),digits.pop();
						digits.push(js(opert,a,b));						
			}		
		}


int main(){
	string s;
	cin >> s;
	opert(s);
	return 0;
}
