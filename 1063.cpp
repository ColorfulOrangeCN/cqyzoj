#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 10000, maxm = 100;

int w[maxn], p[maxm];
int main(){
	int n,m;
	cin >> n >> m;
	fill(p, p + m, 0);
	for (int i = 0; i < n; ++i) cin >> w[i];
	for (int i = 0; i < n; ++i){
		*min_element(p, p + m) += w[i];
	}
	cout << *max_element(p, p + m) << endl;
	return 0;
}
