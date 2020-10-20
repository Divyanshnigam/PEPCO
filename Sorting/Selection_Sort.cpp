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
void selectionsort(int *arr,int n)
{
	int min_i,j;
    for(int i=0;i<n-1;i++)
    {
         min_i=i;
        for( j=i+1;j<n;j++)
        {
            if(issmaller(arr,j,min_i))
            {
                min_i=j;
            }
        }
        swapit(arr,i,min_i);
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
    selectionsort(arr,n);
    print(arr,n);
    return 0;
}/*
Sample Input
5
7 
-2 
4 
1 
3
Sample Output
Comparing -2 and 7
Comparing 4 and -2
Comparing 1 and -2
Comparing 3 and -2
Swapping 7 and -2
Comparing 4 and 7
Comparing 1 and 4
Comparing 3 and 1
Swapping 7 and 1
Comparing 7 and 4
Comparing 3 and 4
Swapping 4 and 3
Comparing 4 and 7
Swapping 7 and 4
-2
1
3
4
7
*/
