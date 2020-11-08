#include <iostream>
#include <cstring>
using namespace std;
void queensCombination(int qsf,int tq,bool chess[][10],int last_cellno)
{
    if(qsf==tq)
    {
        for(int row=0;row<tq;row++)
        {
            for(int col=0;col<tq;col++)
            {
                if(chess[row][col]==true)
                {
                    cout<<"q\t";
                }
                else
                {
                    cout<<"-\t";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int  cell =last_cellno + 1;cell<tq*tq;cell++)
    {
        int row=cell/tq;
        int col=cell%tq;

        chess[row][col]=true;
        queensCombination(qsf+1,tq,chess,cell);
        chess[row][col]=false;
    }    
}
int main() 
{
    int n;
    cin>>n;
    bool chess[n][n];
    queensCombination(0,n,chess,0,-1);
}

