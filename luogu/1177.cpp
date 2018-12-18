#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100001;
int n, a[maxn];/*
void quicksort(int begin, int end)
{
    //cout << begin << endl;
    if(begin >= end) return;
    int i = begin, j = end, k = a[begin];
    while (i < j)
    {
        while(a[j] >= k && i < j) --j;
        swap(a[i], a[j]);
        while(a[i] < k && i < j) ++i;
        swap(a[i], a[j]);
    }
    quicksort(begin, i-1);
    quicksort(i+1, end);
}*/
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1;i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1; i <= n; i++)
    {
        cout << a[i] << ' ';
    }
    return 0;
}