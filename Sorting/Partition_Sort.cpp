#include<iostream>
using namespace std;
void print(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void swapit(int *arr,int i,int j)
{
    cout<<"Swapping "<<arr[i]<<" and "<<arr[j]<<endl;
    swap(arr[i],arr[j]);
}
void partion(int *a,int n,int pivot)
{
    int i=0;
    int j=0;
    while(i<=n)
    {
        if(a[i]>pivot)
        {
            i++;
        }
        else
        {
            swapit(a,i,j);
            i++;
            j++;
        }
    }
    print(a,n);
}
int main()
{
    int pivot,n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>pivot;
    partion(a,n,pivot);
}
