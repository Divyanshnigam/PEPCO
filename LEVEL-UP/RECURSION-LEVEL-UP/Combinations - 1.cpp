#include <iostream>
#include <cstring>
using namespace std;
void combination(int tot_boxes,int cur_boxes,int tot_sel,int ssf,string asf)
{
    if(cur_boxes>tot_boxes)
    {
        if(ssf==tot_sel)
        {
            cout<<asf<<endl;
        }
        return;
    }
    combination(tot_boxes,cur_boxes+1,tot_sel,ssf+1,asf +"i");
    combination(tot_boxes,cur_boxes+1,tot_sel,ssf,asf +"-");
}

int main() 
{
    int n,r;
    cin>>n>>r;
    combination(n,1,r,0,"");
}

