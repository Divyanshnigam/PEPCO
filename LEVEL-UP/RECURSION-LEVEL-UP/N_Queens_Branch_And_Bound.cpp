#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int board[n][n]=0;
	
	bool col[n];
	bool ndig[2*n-1];
	bool rdig[2*n-1];
	
	solve (board,0,col,ndig,rdig,"");
	return 0;
	
}
