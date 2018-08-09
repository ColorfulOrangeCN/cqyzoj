#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 30005;
int a[maxn];
int ans(int n, bool isleft){
	int ans = 0;
	for(int i = 0; i < n; ++i){
		ans += abs(a[i] - a[(n + isleft) / 2]);
	}
	return ans;
}
int main(){
	int n;
	cin >> n;
	for(int i = 0;i <n; ++i) cin >> a[i];
	sort(a,a+n);
	cout << min(ans(n,0), ans(n,1)) << endl;
	return 0;
}
