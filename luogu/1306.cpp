#include<bits/stdc++.h> 
using namespace std;
long long n,m,a = 1, b = 1, c;
int main()
{
    cin>>n>>m;
    int p=__gcd(n,m);//求最大公约数
    for(int i=3;i<=p;i++){
		c = a+b;
		a = b;
		b = c;
	}
	cout << c%100000000 << endl;
    return 0;//完了
}