#include<iostream>
using namespace std;
void swap(int *a , int i , int j)
{
    cout<<"Swapping "<<a[j]<<" and "<<a[i]<<endl;
    swap(a[i],a[j]);
}
int partition(int *a, int s, int e)
{
    int i = s - 1;
    int j = s;
    int pivot = a[e];
    cout<<"pivot -> "<<pivot<<endl;
    for(; j <= e- 1;)
    {
        if(a[j] <= pivot)
        {
            i = i + 1;
            swap(a,i,j);
        }
        j = j + 1;
    }
    swap(a,i+1,e);
    cout<<"pivot index -> "<<i+1<<endl;
    return i+1;
}
void q_s(int *arr, int s, int e)
{
    //base case 
    if(s>e)
    {
        return;
    }
    int p = partition(arr,s,e);
    q_s(arr,s,p-1);
    q_s(arr,p+1,e);
    
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin>>arr[i];
    }
    q_s(arr,0,n-1);
    for(int i = 0 ; i < n ; i++)
    {
        cout<<arr[i]<<" ";
    }
}
