#include <iostream>
#include <map>
using namespace std;
map<int, int> m;
int main(){
	int n;
	cin >> n;
	int t;
	for(int i = 0; i < n; ++i){
		cin >> t;
		map<int, int>::iterator it = m.find(t);
		if(it != m.end()){
		        it->second += 1;
		} else {
			m.insert(make_pair(t, 1));
		}
	}
	for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it){
		cout << it->first << " " << it->second << endl;
       	}
	return 0;
			
}
