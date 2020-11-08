#include <iostream>
#include <cstring>
using namespace std;
void queensCombination(int qsf,int tq,bool chess[][10],int i,int j)
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
    for(int col=j+1;col<tq;col++)
    {
        chess[i][col]=true;
        queensCombination(qsf+1,tq,chess,i,col);
        chess[i][col]=false;
    }
    for(int row=i+1;row<tq;row++)
    {
        for(int col=0;col<tq;col++)
        {
            chess[row][col]=true;
            queensCombination(qsf+1,tq,chess,row,col);
            chess[row][col]=false;
        }
    }
}
int main() 
{
    int n;
    cin>>n;
    bool chess[n][n];
    queensCombination(0,n,chess,0,-1);
}

