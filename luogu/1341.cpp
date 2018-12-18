#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 53;
vector<int> sides[maxn];
int n;
int getpos(char c){
  if(c <= 'z' && c >= 'a')
    return c - 'a' + 1;
  else if(c <= 'Z' && c >= 'A')
    return c - 'A' + 26;
  return 0;
}
void dfs1(int x, int last){
  for(int i = 0; i < sides[x].size(); ++i) {
    int y = sides[x][i];
    if(y == last)continue;
    
  }
}
char backpos(int x){
  if(x <=26 && x >= 1) return x + 'a' - 1;
  else if(x >= 27) return x - 26 + 'A' ;
  return 0;
}
int main(){
  cin >> n;
  char a, b;
  for(int i = 0; i < n; ++i){
    cin >> a >> b;
    sides[getpos(a)].push_back(getpos(b));
    sides[getpos(b)].push_back(getpos(a));
  }
  int cnt = 0, f[2];
  for(int i = 1; i < maxn; ++i){
    if((sides[i].size() & 1 ) == 1){
      if(cnt > 2) {cout << "No Solution" << endl;return 0;}
      f[cnt++] = i;
    }
  }
  if(cnt == 2){
    if(backpos(f[0]) > backpos(f[1])) {
      dfs1(f[1], 0);
    } else {
      dfs1(f[0], 0);
    }
  }
  return 0;
}
