#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 50005;
struct cow{
	int a,b,id;
}cows[maxn];
bool comp1(const cow & a, const cow & b){
	return a.a > b.a;
}

bool comp2(const cow & a, const cow & b){
	return a.b > b.b;
}
int main(){
	int n,k;
	cin >> n >> k;
	for(int i = 0; i < n; ++i){
		cin >> cows[i].a >> cows[i].b;
		cows[i].id = i;
	}
	sort(cows,cows+n,comp1);
	sort(cows,cows+k,comp2);
	cout << cows->id + 1 << endl;
	return 0;
}
