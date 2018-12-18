#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
#define ll long long
#define N 1222222
#define M 2444444
using namespace std;
stack<ll>S;
bool vis[N];
ll n,R[N],L[N],H[N],PA[N],SA[N],PL[N],SL[N],tot;
ll TOT,LA[N],NE[M],EN[M],LE[M],d;
ll GM(ll x,ll y,ll z)
{
	if(x>=y&&x>=z)return x;
	if(y>=z)return y;
	return z;
}
void ADD(ll x,ll y,ll z)
{
	TOT++;
	EN[TOT]=y;
	LE[TOT]=z;
	NE[TOT]=LA[x];
	LA[x]=TOT;
}
ll DFS(ll x,ll f)
{
	if(vis[x])return x;
	vis[x]=1;S.push(x);
	for(ll i=LA[x];i;i=NE[i])
	if(EN[i]!=f)
	{
		ll y=DFS(EN[i],x);
		if(y)return y;
	}
	S.pop();return 0;
}
ll DFSH(ll x,ll f)
{
	ll A=0,B=0;
	for(ll i=LA[x];i;i=NE[i])
	if(EN[i]!=f)
	{
		B=max(B,DFSH(EN[i],x)+LE[i]);
		if(A<B)swap(A,B);
	}
	d=max(A+B,d);
	return A;
}
void FSON(ll x)
{
	ll A=0,B=0;
	for(ll i=LA[R[x]];i;i=NE[i])
	if(EN[i]!=R[x-1]&&EN[i]!=R[x+1])
	{
		ll y=DFSH(EN[i],R[x]);
		B=max(B,y+LE[i]);
		if(A<B)swap(A,B);
	}
	H[x]=A;
	d=max(d,A+B);
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	ll i,j,x,y,z,Maxl,TL,ans;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
 		scanf("%lld%lld%lld",&x,&y,&z);
		ADD(x,y,z);ADD(y,x,z);
	}
	x=DFS(1,0);
	while(!S.empty())
	{
		R[++tot]=S.top();
		S.pop();
		if(R[tot]==x)break;
	}
	R[tot+1]=R[1];R[0]=R[tot];
	for(i=1;i<=tot;i++)
	for(j=LA[R[i]];j;j=NE[j])
	if(EN[j]==R[i+1]){L[i]=LE[j];break;}
	for(i=1;i<=tot;i++)FSON(i);
	
	PA[1]=PL[1]=H[1];
	SA[tot]=SL[tot]=H[tot];
	SA[tot+1]=-1e18;SL[tot+1]=-1e18;
	
	TL=0;for(i=2;i<=tot;i++)TL+=L[i-1],PL[i]=max(PL[i-1],TL+H[i]);
	TL=0;for(i=tot;i>=1;i--)TL+=L[i],SL[i]=max(SL[i+1],TL+H[i]);
	
	Maxl=H[1];
	for(i=2;i<=tot;i++)
	{
		Maxl+=L[i-1];
		PA[i]=max(PA[i-1],H[i]+Maxl);
		Maxl=max(Maxl,H[i]);
	}
	Maxl=H[tot];
	for(i=tot-1;i>=1;i--)
	{
		Maxl+=L[i];
		SA[i]=max(SA[i+1],H[i]+Maxl);
		Maxl=max(Maxl,H[i]);
	}
	ans=max(d,PA[tot]);
	for(i=1;i<=tot;i++)
	ans=min(ans,GM(max(d,PA[i]),SA[i+1],PL[i]+SL[i+1]));
	cout<<ans<<endl;
}
