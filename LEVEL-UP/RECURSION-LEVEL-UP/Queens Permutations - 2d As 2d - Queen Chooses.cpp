#include <iostream>
#include <cstring>
using namespace std;
void queensPermutations(int qsf,int tq,int chess_board[][10])
{
    if(qsf==tq)
    {
        for(int i=0;i<tq;i++)
        {
            for(int j=0;j<tq;j++)
            {
                if(chess_board[i][j]==0)
                {
                    cout<<"-\t";
                }
                else
                {
                    cout<<"q"<<chess_board[i][j]<<"\t";
                }            
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }

    for(int i=0;i<tq;i++)
    {
        for(int j=0;j<tq;j++)
        {
            if(chess_board[i][j]==0)
            {
                chess_board[i][j]=1;
                queensPermutations(qsf+1,tq,chess_board);
                chess_board[i][j]=0;
            }
        }
    }
}
int main() 
{
    int n;
    cin>>n;
    int chess_board[n][n]={0};
    queensPermutations(0,n,chess_board);
}

