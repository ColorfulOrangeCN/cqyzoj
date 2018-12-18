#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100001;
int f[maxn][32], f2[maxn][32], A[maxn], logger[maxn];
int n, k;
void init(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) scanf("%d",A+i);
	logger[1] = 0;
	for(int i = 2; i <= n; ++i){
		logger[i] = logger[(i >> 1)] + 1;
	}
	int maxLog = logger[n];
	for(int i = 1; i <= n; ++i){
		f[i][0] = A[i];
		f2[i][0] = A[i];
	}
	for(int j = 1; j <= maxLog; ++j){
		for(int i = 1; i+(1 << j) - 1 <= n; ++i){
			f[i][j] = max(f[i][j-1], f[i+(1 << (j-1))][j-1]);
			f2[i][j] = min(f2[i][j-1], f2[i+(1 << (j-1))][j-1]);
		}
	}
}

void solve(){
	/*
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= 5; ++j){
			printf("%d ", f2[i][j]);
		}
		printf("\n");
	}*/
	int a,b,maxa = n - k + 1;
	for(int i = 1; i <= maxa; ++i){
		a = i;
		b = a + k - 1;
		printf("%d %d\n",max(f[a][logger[b - a+1]], f[b-(1 << logger[b-a+1])+1][logger[b-a+1]]),
		       min(f2[a][logger[b - a+1]], f2[b-(1 << logger[b-a+1])+1][logger[b-a+1]]));
	}
}
int main(){
	init();
	solve();
	return 0;
}
