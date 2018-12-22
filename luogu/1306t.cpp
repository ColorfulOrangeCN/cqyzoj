#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[1000000];
int main()
{
    cin>>n>>m;
    int p=__gcd(n,m);//求最大公约数
    a[1]=1;
    a[2]=1;
    for(int i=3;i<=p;i++)a[i]=(a[i-1]+a[i-2])%100000000;
    cout<<a[p]<<endl;//输出
    return 0;//完了
}