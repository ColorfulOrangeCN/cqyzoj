#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10000005;
int a[maxn];
int main(){
  int n;
  cin >> n;
  int t;
  fill(a,a+n+1,0);
  for(int i = 0;i < n; ++i)cin >> t, a[t] += 1;
  int now = 0;
  for(int i = 0;i < n && i < 1000; ++i){
	  while(a[now] == 0)++now;
	  a[now] -= 1;
	  cout << now << ' ';
  }
  return 0;
}
