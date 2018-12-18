#include <iostream>
using namespace std;
const int maxn = 21;
char a[maxn][maxn];
int n,m,minans = 5000,beginx,beginy,endx,endy;
const int ca[]={0,0,-1,1},cb[]={-1,1,0,0};
void ans(int x,int y, int now){
	if(x == endx && y == endy){
		if(now < minans){
			minans = now;
		}
		return;
	}
	a[x][y] = '0';
	for(int i = 0;i < 3; ++i){
		int tx = x + ca[i],ty = y + cb[i];
		if(tx < m && ty < n && a[tx][ty] == '1'){
			ans(tx,ty,now+1);
		}
	}
	a[x][y] = '1';
}
int main(){
	cin >> m >> n;
	for(int i = 0;i < m; ++i)
		for(int j = 0;j < n; ++j)
			cin >> a[i][j];
	cin >> beginx >> beginy >> endx >> endy;
	--beginx,--beginy,--endx,--endy;
	ans(beginx,beginy,0);
	cout << minans << endl;
	return 0;
}
