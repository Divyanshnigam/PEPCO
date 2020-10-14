#include<iostream>
#include<list>
using namespace std;
bool check(int *a,int j)
{
	int i=0;
	while(i<=j)
	{
		if(a[i]==a[j])
		{
			i++;
			j--;
			return true;
		}
		else
		{
			return false; 
		}
	}
	return false;
}

int main()
{
	list<int> l;
	int n,a[1000];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		l.push_back(a[i]);
	}
	int j=n-1;
	int pal=check(a,j);
	if(pal)
	{
		cout<<"true";
	}
	else{
		cout<<"false";
	}
	return 0;
}
