#include<iostream>
using namespace std;
void swap(int bc, int up, int **arr)
{
    //base case
    if(bc == up)
    {
        for(int i = 0 ; i < up ; i++)
        {
            for(int j = 0 ; j < up ; j++)
            {
                if(arr[i][j] == 0)
                {
                    cout<<"-\t";
                }
                else
                {
                    cout<<"q"<<arr[i][j]<<"\t";
                }
                
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int i = 0 ; i < up ; i++)
    {
        for(int j = 0 ; j < up ; j++)
        {
            if(arr[i][j] == 0)
            {
                arr[i][j] = bc + 1;
                swap(bc+1,up,arr);
                arr[i][j] = 0;
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int** arr = new int*[n+1];
    for(int i = 0 ; i < n ; i++)
    {
        arr[i] = new int[n+1];
        for(int j = 0 ; j < n ; j++)
        {
            cin>>arr[i][j];
        }
    }
    swap(0,n,arr);
    
}
