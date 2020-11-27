#include<iostream>
#include<stack>
using namespace std;
void printSpan(int arr[], int n)
{
	stack <int> s;
	int ans[100] ={};
	for(int day=0;day<n;++day)
	{
		int curPrice = arr[day];
		while(s.empty() == false && arr[s.top()]<curPrice)   //for day=0 1st time the stack is empty.....2nd time arr[0]=100>arr[1]....3rd time arr[1]=80>arr[2].....4th time arr[2]=60<arr[3]      
		{
			s.pop();                                        // false..........................................false...................false........................true & s{0,1}
		}
		int betterdays = s.empty() ? 0: s.top();            // 1st time true hence 0..................s.top=0 hence 0................s.top()=1 hence 1............s.top=1 hence 1
		int span = day - betterdays;                       // 0-0=0 ..............................1-0=1...........................2-1=1...........................3-1=2
		ans[day] = span;                                   // ans[0]=0.............................ans[1]=1........................ans[2]=1.......................ans[3]=2
		s.push(day);                                       // s{0}...................................s{0,1}........................s{0,1,2}.........................s{0,1,3}..
	}                                                               //_________________and so on.....................            .......          .....      ...  ..   .
	for(int i = 0 ; i < n ; i++)
	{
		cout<<ans[i]<<" ";
	}
}
int main()
{
	int n = 7;
	int arr[100] = {100 , 80 , 60 , 70 , 60 , 75 , 85};
	printSpan(arr,n);
	
	return 0;
}
// 0 1 1 2 1 4 6
