#include <iostream>
#include <cstring>
using namespace std;
void permutation(int *boxes,int cur_item,int tot_item,int n)
{
    if(cur_item>tot_item)
    {
        for(int i=0;i<n;i++)
        {
            cout<<boxes[i];
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(boxes[i]==0)
        {
            boxes[i]=cur_item;
            permutation(boxes,cur_item+1,tot_item,n);
            boxes[i]=0;
        }
    }
}

int main() 
{
    int n,r;
    cin>>n>>r;
    int a[n]={0};
    permutation(a,1,r,n);
}

