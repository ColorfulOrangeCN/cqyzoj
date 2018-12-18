#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#define N 1005
using namespace std;
char map[N][N];
int n,cntx,cnty;
bool No=1;
int Calx()
{
	for(int i=1;i<=n;i++)
	{
		int k=1;
		for(int j=1;j<=n;j++)if(map[i][j]=='.')k=0;
		cntx+=k;
	}
}
int Caly()
{
	for(int i=1;i<=n;i++)
	{
		int k=1;
		for(int j=1;j<=n;j++)if(map[j][i]=='.')k=0;
		cnty+=k;
	}
}
int Cal(int x)
{
	int i,j,k=1,cnt=0;
	for(i=1;i<=n;i++)if(map[i][x]=='#')k=0;
	for(i=1;i<=n;i++)cnt+=map[x][i]=='.';
	return cnt+k;
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int i,j,Min=1e9;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%s",&map[i][1]);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)if(map[i][j]=='#')No=0;
	if(No)return puts("-1"),0;
	Calx();Caly();
	if(cntx==n)return puts("0"),0;
	if(cntx!=0)return printf("%d",n-cnty),0;
	for(i=1;i<=n;i++)Min=min(Min,Cal(i)+n-cnty);
	printf("%d",Min);
}
