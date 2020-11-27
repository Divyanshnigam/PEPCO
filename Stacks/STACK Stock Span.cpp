#include<iostream>
#include<stack>
using namespace std;
void stockspan(int price[],int n,int span[])
{
	stack<int>s;   //will contain indices of days
	s.push(0);  // 0th index day
	span[0]=1; //by default be 1 becoz no prev. stacks
	for(int i=1;i<=n;i++)
	{
		int currprice=price[i];
		while(!s.empty() and price[s.top()]<=currprice)
		{
			s.pop();   // poped becoz we will search the prev greater price not for lesser one..
		}   //as we found that price
		if(!s.empty())  //if that found == !empty 
		{
			int pre_highest=s.top();    //stored its index
			span[i]=i-pre_highest;    //assigned in span array
		}
		else{
			span[i]=i+1;  // else corner case applied
		}
		s.push(i);   // pushed that day index
	}

}
int main() 
{
	int n,price[1000];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>price[i];
	}
	int span[1000]={0};
	stockspan(price,n,span);
	for(int i=0;i<n;i++)
	{
		cout<<span[i]<<" ";
	}
	cout<<"END";
	return 0;
}
