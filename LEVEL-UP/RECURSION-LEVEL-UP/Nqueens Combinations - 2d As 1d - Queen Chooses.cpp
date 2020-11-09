#include<iostream>
#include<cstring>
using namespace std;
bool IsQueenSafe(bool chess[][10], int row, int col,int tq) 
{
    for(int i=row,j=col;i>=0;i--)
    {
        if(chess[i][j])
        {
            return false;
        }
    }
    for(int i=row,j=col;j>=0;j--)
    {
        if(chess[i][j])
        {
            return false;
        }
    }
    for(int i=row,j=col;i>=0 and j>=0;i--,j--)
    {
        if(chess[i][j])
        {
            return false;
        }
    }
    for(int i=row,j=col;i>=0 and j<tq;i--,j++)
    {
        if(chess[i][j])
        {
            return false;
        }
    }
    return true;
}

void nqueens(int qpsf, int tq, bool chess[][10], int lcno) {
        if(qpsf == tq) {
            for(int row = 0; row < tq; row++) {
                for (int col = 0; col < tq; col++) {
                    cout<<chess[row][col] ? "q\t" : "-\t";
                }
                cout<<endl;
            }
            cout<<endl;
            return;
        }

        for (int i = lcno + 1; i < tq * tq; i++) {
            int row = i / tq;
            int col = i % tq;

            if (chess[row][col] == false && IsQueenSafe(chess, row, col,tq)) {
                chess[row][col] = true;
                nqueens(qpsf + 1, tq, chess, row * tq + col);
                chess[row][col] = false;
            }
        }
    }

int main() 
{
    int n;
    cin>>n;
    bool chess[n][n];
    nqueens(0, n, chess, -1);
    return 0;
}
