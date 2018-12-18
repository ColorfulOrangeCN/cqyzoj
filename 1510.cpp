#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
	int K;
	cin >> K;
	priority_queue<int,vector<int>,greater<int>> q;
	q.push(1);
	--K;
	while(K != 0){
		int now = q.top();
		q.push(2 * now + 1);
		q.push(3 * now + 1);
		q.pop();
		--K;
		//cout << now << endl;
	}
	cout << q.top() << endl;
}
