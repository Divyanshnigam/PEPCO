#include<iostream>
#include<algorithm>
using namespace std;
void targetsum(int *a,int ts,int n)
{
    int l=0;
    int r=n;
    while(l<r)
    {
        if(a[l]+a[r]<ts)
        {
            l++;
        }
        else if(a[l]+a[r]>ts)
        {
            r--;
        }
        else
        {
            cout<<a[l]<<", "<<a[r]<<endl;
            l++;
            r--;
        }
    }
}
int main()
{
    int n,ts;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>ts;
    sort(a,a+n);
    targetsum(a,ts,n-1);
}
