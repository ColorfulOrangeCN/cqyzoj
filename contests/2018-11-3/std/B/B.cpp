#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<assert.h>
#define N 1000005
using namespace std;
const int mod=998244353;
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
int mul(int a,int b){return 1ll*a*b%mod;}
int ksm(int a,int b){int o;for(o=1;b;b>>=1,a=mul(a,a))if(b&1)o=mul(o,a);return o;}
int n,l1,l2,len[26],fa[N],sum1,sum2,S,T,ans;
bool mark[N];
char s1[N],s2[N];
vector<int>pos[26];
int gf(int x){return fa[x]==x?x:fa[x]=gf(fa[x]);}
void Merge(int x,int y)
{
	x=gf(x);y=gf(y);
	if(x!=y)fa[x]=y;
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int i,j,k,x,y;char c;
	scanf("%s",s1+1);l1=strlen(s1+1);
	scanf("%s",s2+1);l2=strlen(s2+1);
	assert(l1<=1000000);
	assert(l2<=1000000);
	scanf("%d",&n);
	S=1000001;T=S+1;
	for(i=1;i<=T;i++)fa[i]=i;
	for(i=1;i<=n;i++)scanf("\n%c%d",&c,&k),len[c-'a']=k;
	for(i=1;i<=l1;i++)
	{
		if(s1[i]=='0')sum1++,Merge(sum1,S);
		else if(s1[i]=='1')sum1++,Merge(sum1,T);
		else pos[s1[i]-'a'].push_back(sum1),sum1+=len[s1[i]-'a'];
	}
	for(i=1;i<=l2;i++)
	{
		if(s2[i]=='0')sum2++,Merge(sum2,S);
		else if(s2[i]=='1')sum2++,Merge(sum2,T);
		else pos[s2[i]-'a'].push_back(sum2),sum2+=len[s2[i]-'a'];
	}
	for(i=0;i<26;i++)
	for(j=1;j<=len[i];j++)
	for(k=1;k<pos[i].size();k++)Merge(pos[i][k-1]+j,pos[i][k]+j);
	int fx=gf(S),fy=gf(T);
	if(fx==fy)return puts("0"),0;
	for(i=1;i<=sum1;i++)
	{
		x=gf(i);if(x==fx||x==fy)continue;
		if(!mark[x])mark[x]=1,ans++;
	}
	printf("%d\n",ksm(2,ans));
}
