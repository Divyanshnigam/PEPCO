/*given n=no. of people,k=no. of skip to kill.
find the last most peson to survive.*/
#include<iostream>
using namespace std;
int solve(int n,int k)
{
	if(n==1)
	{
		return 0;
	}
	int x=solve(n-1,k);
	int y=(x+k)%n;
	return y;
}
int main()
{
	int n,k;
	cin>>n>>k;
	cout<<solve(n,k);
}
