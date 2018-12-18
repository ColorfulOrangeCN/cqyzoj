#include <iostream>
#include <string>
using namespace std;
const int maxn = 10005;
int ps[maxn];
int get_boss(int now) {
    if(ps[now] != now) {
	return ps[now] = get_boss(ps[now]);
    } else {
	return now;
    }
}
void do_merge(int a, int b){
    ps[get_boss(a)] = get_boss(b);
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
	ps[i] = i;
    }
    for(int i = 0; i < m ;++i) {
	string c;
	cin >> c;
	if(c == "S"){
	    int t;
	    cin >> t;
	    ps[t] = t;
	} else {
	    int a, b;
	    cin >> a >> b;
	    do_merge(a,b);
	}
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
	if(get_boss(i) == i) {
	    ++ans;
	}
    }
    cout << ans << endl;
    return 0;
}
