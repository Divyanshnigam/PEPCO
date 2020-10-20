#include<iostream>
using namespace std;
void swapit(int *arr,int i,int j)
{
    cout<<"Swapping "<<arr[i]<<" and "<<arr[j]<<endl;
    swap(arr[i],arr[j]);
}
int partition(int *arr, int pivot, int lo, int hi) 
{
    cout<<"pivot -> "<<pivot<<endl;
    int i = lo, j = lo;
    while (i <= hi) 
    {
      if (arr[i] <= pivot) 
      {
        swapit(arr, i, j);
        i++;
        j++;
      } 
      else 
      {
        i++;
      }
    }
    cout<<"pivot index -> "<<(j - 1)<<endl;
    return (j - 1);
}
int quickselect(int *a,int lo,int hi,int k)
{
    int pivot=a[hi];
    int pi=partition(a,pivot,lo,hi);
    if(k>pi)
    {
        quickselect(a,pi+1,hi,k);
    }
    else if(k<pi)
    {
        quickselect(a,lo,pi-1,k);
    }
    else
    {
        return pivot;
    }
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
    int select;
    cin>>select;
    cout<<quickselect(a,0,n-1,select-1);
}
