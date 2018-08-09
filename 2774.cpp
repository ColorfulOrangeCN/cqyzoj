#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000005;
struct temp{
	int v;
	int id;
	bool operator < (const temp & a){
		return v != a.v ? v > a.v : id < a.id;
	}
}a[maxn];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a[i].v;
		a[i].id = i + 1;
	}
	sort(a,a+n);
	for(int i = 0; i < n; ++i){
		cout << a[i].v << ' ' << a[i].id << endl;
	}
	return 0;
}
