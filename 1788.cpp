#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef unsigned long long ul;
int main(){
	int n,k;
	cin >> n >> k;
	unsigned long  now = n, val = pow(10,k), cnt = 1;
	const int t = n % val;
	now *= n;
	while(now % val != t){
		++cnt;
		now *= n;
	}
	cout << cnt << endl;
}
