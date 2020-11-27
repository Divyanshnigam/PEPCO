#include<iostream>
using namespace std;
int main() 
{
	int n,a[1000],p[1000]={-1};
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(a[i]<a[j])
			{
				p[i]=a[j];
				break;
			}
			else 
			{
				for(int t=0;t<i;t++)
				{
					if(a[i]<a[t])
					{
						p[i]=a[t];
						break;
					}
					else
		         	{
					    p[i]=-1;
					}					
				}
			}
		}	
	}
	for(int i=0;i<n;i++)
	{
		cout<<p[i]<<" ";
	}
	return 0;
}
