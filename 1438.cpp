#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 500005;
struct city{
	int left,right;
} citys[maxn];
int mark[maxn];
bool compare(city a, city b){
	return a.left < b.left;
}
int main(){	
	ios::sync_with_stdio(false);	
	int N;
	cin >> N;
	for(int i = 0; i < N;++i){
		cin >> citys[i].left >> citys[i].right;
	}
	sort(citys,citys + N, compare);
	int cnt = 1;
	mark[1] = citys[0].right;
	for(int i = 1; i < N; ++i){
		int t = upper_bound(mark+1,mark+cnt+1,citys[i].right)-mark;
		mark[t] = citys[i].right;
		if(t > cnt){
			cnt = t;
		}
	}	
	cout << cnt << endl;
	return 0;
}
