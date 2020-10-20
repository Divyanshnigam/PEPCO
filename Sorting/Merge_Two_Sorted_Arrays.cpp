#include<iostream>
using namespace std;
void print(int *c,int k)
{
    for(int i=0;i<k;i++)
    {
        cout<<c[i]<<endl;
    }
}
void merge(int *a,int *b,int n,int m)
{
    int c[n+m];
    int i,j,k;
    i=j=k=0;
    while(i<n and j<m)
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            i++;
            k++;
        }
        else
        {
            c[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<n)
    {
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<m)
    {
        c[k]=b[j];
        j++;
        k++;
    }
    print(c,k);
}
int main()
{
    int n,m;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    merge(a,b,n,m);
}
