#include <iostream>
#include <cstring>
using namespace std;
void permutation(int tot_boxes,int cur_boxes,int *ritem,int ssf,int tot_sel,string asf)
{
    if(cur_boxes>tot_boxes)
    {
        if(ssf==tot_sel)
        {
            cout<<asf<<endl;
        }
        return;
    }
    for(int i=0;i<tot_sel;i++)
    {
        if(ritem[i]==0)
        {
            ritem[i]=1;
            permutation(tot_boxes,cur_boxes+1,ritem,ssf+1,tot_sel,asf + to_string(i+1));
            ritem[i]=0;
        }
    }
    permutation(tot_boxes,cur_boxes+1,ritem,ssf,tot_sel,asf + to_string(0));

}

int main() 
{
    int n,r;
    cin>>n>>r;
    int ritem[r]={0};
    permutation(n,1,ritem,0,r,"");
}

