#include<iostream>
using namespace std;
void print(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
bool isgreater(int *arr,int i,int j)
{
    cout<<"Comparing "<<arr[j]<<" and "<<arr[i]<<endl;
    if(arr[i]>arr[j]){
        return true;
    }
    return false;
}
void swapit(int *arr,int i,int j)
{
    cout<<"Swapping "<<arr[i]<<" and "<<arr[j]<<endl;
    swap(arr[i],arr[j]);
}
void insertionsort(int *arr,int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(isgreater(arr,j,j+1))
            {
                swapit(arr,j,j+1);
            }
            else
            {
                break;
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
    insertionsort(arr,n);
    print(arr,n);
    return 0;
}
/*
Sample Input
5
7 
-2 
4 
1 
3
Sample Output
Comparing -2 and 7
Swapping 7 and -2
Comparing 4 and 7
Swapping 7 and 4
Comparing 4 and -2
Comparing 1 and 7
Swapping 7 and 1
Comparing 1 and 4
Swapping 4 and 1
Comparing 1 and -2
Comparing 3 and 7
Swapping 7 and 3
Comparing 3 and 4
Swapping 4 and 3
Comparing 3 and 1
-2
1
3
4
7
*/
