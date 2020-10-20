#include<iostream>
using namespace std;
void print(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
bool issmaller(int *arr,int i,int j)
{
    cout<<"Comparing "<<arr[i]<<" and "<<arr[j]<<endl;
    if(arr[i]<arr[j]){
        return true;
    }
    return false;
}
void swapit(int *arr,int i,int j)
{
    cout<<"Swapping "<<arr[i]<<" and "<<arr[j]<<endl;
    swap(arr[i],arr[j]);
}
void bubblesort(int *arr,int n)
{
    for(int itr=1;itr<=n-1;itr++)
    {
        for(int j=0;j<n-itr;j++)
        {
            if(issmaller(arr,j+1,j))  //   seeking if j+1 the next element if greater then swap 
            {
                swapit(arr,j+1,j);
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bubblesort(arr,n);
    print(arr,n);
    return 0;
}
/*
Sample Input
5
7 -2 4 1 3

Sample Output

Comparing -2 and 7
Swapping -2 and 7
Comparing 4 and 7
Swapping 4 and 7
Comparing 1 and 7
Swapping 1 and 7
Comparing 3 and 7
Swapping 3 and 7
Comparing 4 and -2
Comparing 1 and 4
Swapping 1 and 4
Comparing 3 and 4
Swapping 3 and 4
Comparing 1 and -2
Comparing 3 and 1
Comparing 1 and -2
-2
1
3
4
7
*/
