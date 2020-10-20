#include<iostream>
using namespace std;
void targetsum(int *a,int n)
{
    int lo=0;
    int hi=n;
    while(lo<hi)
    {
        int mid=(lo+hi)/2;
        if(a[mid]<a[hi])
        {
            hi=mid;
        }
        else
        {
            lo=mid+1;
        }
    }
    cout<< a[hi];
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    targetsum(a,n-1);
}
