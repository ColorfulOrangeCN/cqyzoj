#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 200001;
int f[maxn][32], A[maxn], logger[maxn];
int n,m;
void init(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d",A+i);
	logger[1] = 0;
	for(int i = 2; i <= n; ++i){
		logger[i] = logger[(i >> 1)] + 1;
	}
	int maxLog = logger[n];
	for(int i = 1; i <= n; ++i){
		f[i][0] = A[i];
	}
	for(int j = 1; j <= maxLog; ++j){
		for(int i = 1; i+(1 << j) - 1 <= n; ++i){
			f[i][j] = max(f[i][j-1], f[i+(1 << (j-1))][j-1]);
		}
	}
}

void solve(){
	int a,b;
  scanf("%d", &m);
	for(int i = 0; i < m; ++i){
		scanf("%d%d", &a ,&b);
		printf("%d\n",max(f[a][logger[b - a+1]], f[b-(1 << logger[b-a+1])+1][logger[b-a+1]]));
	}
}
int main(){
	init();
	solve();
	return 0;
}
