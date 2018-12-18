#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
const int maxn = 10005;
struct node{
  int v, id;
  bool operator <(const node & another) const {
    return v < another.v;
  }
}a[maxn];
int n,rets[maxn];
int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i].v;
    a[i].id = i;
  }
  sort(a, a + n);
  for(int i = 0; i < n; ++i){
    rets[a[i].id] = i;
  }
  copy(rets, rets+n, ostream_iterator<int>(cout , " "));
}
