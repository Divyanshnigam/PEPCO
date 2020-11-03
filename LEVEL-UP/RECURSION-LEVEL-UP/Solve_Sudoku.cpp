#include<iostream>
using namespace std;
void display(int board[10][10])
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}
bool isvalid(int board[10][10],int x,int y,int val)
{
		for(int j=0;j<10;j++)
		{
			if(board[x][j]==val)
			{
				return false;
			}
		}
		for(int i=0;i<10;i++)
		{
			if(board[i][y]==val)
			{
				return false;
			}
		}
		int smi=x/3*3;
		int smj=y/3*3;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(board[smi+i][smj+j]==val)
				{
					return false;
				}
			}
		}
		return true;
}
void solve(int board[10][10],int i,int j)
{
	if(i==10)
	{
		display(board);
		return;
	}
	int ni=0;
	int nj=0;
	if(j==9)
	{
		ni=i+1;
		nj=0;
	}
	else
	{
		ni=i;
		nj=j+1;
	}
	if(board[i][j]!=0)
	{
		solve(board,ni,nj);
	}
	else
	{
		for(int po=1;po<10;po++)
		{
			if(isvalid(board,i,j,po)==true)
			{
				board[i][j]=po;
				solve(board,ni,nj);
				board[i][j]=0;  //backtracking...
			}
		}
	}
}
int main()
{
	int board[10][10];
	for(int i=0;i<=9;i++)
	{
		for (int j=0;j<=9;j++)
		{
			cin>>board[i][j];
		}
	}
	solve(board,0,0);
}
