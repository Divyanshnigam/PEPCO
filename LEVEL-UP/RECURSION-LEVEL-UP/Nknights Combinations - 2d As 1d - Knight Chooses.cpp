#include<iostream>
#include<cstring>
using namespace std;
bool IsKnightSafe(bool chess[][10], int i, int j,int tk) 
{
    if(i-1>=0 and j-2>=0 and chess[i-1][j-2])
    {
        return false;
    }
    if(i-2>=0 and j-1>=0 and chess[i-2][j-1])
    {
        return false;
    }
    if(i-2>=0 and j+1<tk and chess[i-2][j+1])
    {
        return false;
    }
    if(i-1>=0 and j-2>=tk and chess[i-1][j+2])
    {
        return false;
    }
    return true;
}

    void nknights(int kpsf, int tk, bool chess[][10], int lcno) 
    {
        if (kpsf == tk) {
            for (int row = 0; row < tk; row++) {
                for (int col = 0; col <tk; col++) {
                    cout<<chess[row][col] ? "k\t" : "-\t";
                }
                cout<<endl;
            }
            cout<<endl;
            return;
        }

        for (int i = lcno + 1; i < tk * tk; i++) {
            int row = i / tk;
            int col = i % tk;

            if (chess[row][col] == false && IsKnightSafe(chess, row, col,tk)) {
                chess[row][col] = true;
                nknights(kpsf + 1, tk, chess, row *tk + col);
                chess[row][col] = false;
            }
        }
    }

int main()
{
    int n;
    cin>>n;
    bool chess[n][n];
    nknights(0, n, chess, -1);
}

