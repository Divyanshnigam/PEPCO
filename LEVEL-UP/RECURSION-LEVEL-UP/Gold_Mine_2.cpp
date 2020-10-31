#include<iostream>
#include<vector>
using namespace std;
void travelandcollectgold(int *a,int i,int j,vector<int>bag,bool visited,int n,int m)
{
	if(i<0 or j<0 or i>=n or j>=m or a[i][j]==0 or visited[i][j]==true)
	{
		return;
	}
	
	visited[i][j]=true;
	bag.push_back(a[i][j]);
	//n e w s 
	travelandcollectgold(a,i-1,j,bag,visited,n,m);//n
	travelandcollectgold(a,i,j+1,bag,visited,n,m);//e
	travelandcollectgold(a,i,j-1,bag,visited,n,m);//w
	travelandcollectgold(a,i+1,j,bag,visited,n,m);//s
	
}
void getmaxgold(int *a,int n,int m)
{	
	bool visited[n][m]={false};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]!=0 and visited[i][j]==false)
			{
				vector<int>bag;
				travelandcollectgold(a,i,j,bag,visited,n,m);
				
				int sum=0;
				for(int val:bag)
				{
					
					sum+=val;
				}
				if(sum>max)
				{
					max=sum;
				}
			}
		}
	}	
}
int main()
{
	int n,m;
	cin>>n>>m;
	int a[n][m];
	for (int i=0i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	getmaxgold(a,n,m);
}
