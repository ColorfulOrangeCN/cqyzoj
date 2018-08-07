#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct per{
	string name;
	int n;
};

bool operator <(const per& a, const per& b){
	return a.n == b.n ? a.name < b.name : a.n > b.n;
}

int main(){
	int n;
	cin >> n;
	vector<per>pers(n);
	for(int i = 0; i < n; ++i){
		cin >> pers[i].name;
		pers[i].n = 0;
		for(size_t j = 0; j < pers[i].name.size();++j){
			pers[i].n += pers[i].name[j];
		}
	}
	sort(pers.begin(),pers.end());
	for(int i = 0; i < n; ++i){
		cout << pers[i].name << endl;
	}
	return 0;
}
