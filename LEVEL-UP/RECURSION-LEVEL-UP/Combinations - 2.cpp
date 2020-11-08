#include <iostream>
#include <cstring>
using namespace std;
void combination(int n,int *nbox,int cur_item,int tot_item,int last_box)
{
    if(cur_item>tot_item)
    {
        for(int i=0;i<n;i++)
        {
            if(nbox[i])
            {
                cout<<"i";
            }
            else
            {
                cout<<"-";
            }
        }
        cout<<endl;
        return;
    }
    for(int b=last_box+1;b<n;b++)
    {
        if(nbox[b]==0)
        {
            nbox[b]=1;
            combination(n,nbox,cur_item+1,tot_item,b);
            nbox[b]=0;
        }
    }   
}

int main() 
{
    int n,r;
    cin>>n>>r;
    int nbox[n]={0};
    combination(n,nbox,1,r,-1);
}

