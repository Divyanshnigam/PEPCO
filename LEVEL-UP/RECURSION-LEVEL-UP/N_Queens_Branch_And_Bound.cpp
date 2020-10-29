#include<iostream>
#include<cstring>
using namespace std;
void solve( bool board,int row,bool cols,bool ndig,bool rdig ,string asf,int n)
{
	for(int col=0;col<n;col++)
	{
        if(row==n)
        {
            cout<<asf<<"."<<endl;
        }
		if(cols[col]==false and ndig[row+col]==false and rdig[row+col +n-1])
		{
			cols[col]==true;
            ndig[row+col]==true;
            rdig[row-col+n-1]==true;
            board[row][cols]==true;
        	solve (board,row+1,cols,ndig,rdig,asf + to_string(row) +"-" + to_string(col),n);
			cols[col]==false;
            ndig[row+col]==false;
            rdig[row-col+n-1]==false;
            board[row][cols]==false;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	bool board[n][n]=false;
	
	bool cols[n];
	bool ndig[2*n-1];
	bool rdig[2*n-1];
	
	solve (board,0,cols,ndig,rdig,"",n);
	return 0;
	
}
