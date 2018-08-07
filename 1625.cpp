#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 100005;
vector<int> a[maxn];
bool check[maxn] = {false};
int N, M;
int do_DFS(int now){
	check[now] = true;
	//cout << now << " ";
	int ret = 1;
	for(int i = 0; i < a[now].size(); ++i){
		if(!check[a[now][i]]){
			ret += do_DFS(a[now][i]);
		}
	}
	return ret;
}


int main(){
	cin >> N >> M;
	int x,y;
	for(int i = 0; i < M; ++i){
		cin >> x >>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	int ans = 0;
	int maxd = -1;
	for(int i = 1; i <= N; ++i){
		if(!check[i]){
			int t = do_DFS(i);
			if(t > maxd){
				maxd = t;
			}
			++ans;
		}
	}
	cout << ans << endl << maxd << endl;
}
