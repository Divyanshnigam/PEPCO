#include<bits/stdc++.h>
using namespace std;
int slide(int *a ,int n,int k)
{
 //   vector<int> slider;
    int i=0,j=0,sum=0,maxi=0;
    while(j<n)
    {
        sum+=a[j];
        if(j-i+1<k)
        {
            j++;
        }
        else if(j-i+1 == k)
        {
            maxi=max(maxi,sum);
            sum-=a[i];
            i++;
            j++;
        }
   }
    return maxi;
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
    int k;
    cin>>k;
    cout<<slide(a,n,k);
}