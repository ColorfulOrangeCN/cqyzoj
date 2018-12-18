#include<stdio.h>
#include<algorithm>
#define MAX_N 1000001
typedef struct _t{
	int s, f;
}t;

bool operator < (const t&a, const t&b){
	return double(a.s)/a.f > double(b.s)/b.f;
}

t ts[MAX_N];
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i){
		scanf("%d%d", &ts[i].s, &ts[i].f);
	}
	std::sort(ts, ts+n);
	int s = 0, f = 0;
	for(int i = 0; i < k; ++i){
		s += ts[i].s, f += ts[i].f;
	}
	s *= 100;
	double ans = double(s)/f;
        ans += 0.0005;
	ans = int(ans*1000)/1000;
     	printf("%.3lf", ans);
	return 0;
}
