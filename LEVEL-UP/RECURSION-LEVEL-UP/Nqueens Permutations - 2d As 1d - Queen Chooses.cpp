#include<iostream>
#include<cstring>
using namespace std;
bool IsQueenSafe(int** chess, int row, int col,int tq) 
{
    for(int i=row,j=col;i>=0;i--)
    {
        if(chess[i][j]>0)
        {
            return false;
        }
    }
    for(int i=row,j=col;i<tq;i++)
    {
        if(chess[i][j]>0)
        {
            return false;
        }
    }
    for(int i=row,j=col;j>=0;j--)
    {
        if(chess[i][j]>0)
        {
            return false;
        }
    }
    for(int i=row,j=col;j<tq;j++)
    {
        if(chess[i][j]>0)
        {
            return false;
        }
    }
    for(int i=row,j=col;i>=0 and j>=0;i--,j--)
    {
        if(chess[i][j]>0)
        {
            return false;
        }
    }
    for(int i=row,j=col;i>=0 and j<tq;i--,j++)
    {
        if(chess[i][j]>0)
        {
            return false;
        }
    }
    for(int i=row,j=col;i<tq and j<tq;i++,j++)
    {
        if(chess[i][j]>0)
        {
            return false;
        }
    }
    for(int i=row,j=col;i<tq and j>=0;i++,j--)
    {
        if(chess[i][j]>0)
        {
            return false;
        }
    }
    return true;
}

void nqueens(int qpsf, int tq, int **chess) 
{
    if(qpsf==tq)
    {
        for (int i=0;i<tq;i++)
        {
            for(int j=0;j<tq;j++)
            {
                if(chess[i][j]==0)
                {
                    cout<<"-\t";
                }
                else
                {
                    cout<<"q"<<chess[i][j]<<"\t";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int  cell =0;cell<tq*tq;cell++)
    {
        int row=cell/tq;
        int col=cell%tq;

        if(chess[row][col]==0 and IsQueenSafe(chess,row,col,tq))
        {
            chess[row][col]=qpsf+1;
            nqueens(qpsf+1,tq,chess);
            chess[row][col]=0;
        }
    }    
}

int main()
{
    int n;
    cin>>n;
    int** chess_board = new int*[n+1];
    for(int i = 0 ; i < n ; i++)
    {
        chess_board[i] = new int[n+1];
        for(int j = 0 ; j < n ; j++)
        {
            chess_board[i][j]=0;
        }
    }
    nqueens(0, n, chess_board);
}

