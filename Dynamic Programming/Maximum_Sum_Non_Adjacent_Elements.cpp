#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int in[100]={0};
    int ex[100]={0};
    in[0]=a[0];
    for(int i=1;i<n;i++)
    {
        in[i]=a[i]+ex[i-1];
        ex[i]=max(in[i-1],ex[i-1]);
    }
    cout<<max(in[n-1],ex[n-1]);
    return 0;
}
/*
V\Sample Input
6
5
10
10
100
5
6
Sample Output
116
*/
