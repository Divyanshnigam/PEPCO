#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
bool checkexpression(string str)
{
	stack<char>s;
	for(int i=0;i<str.size();i++)
	{
		char cur=str[i];
		if(cur=='(')
		{
			s.push(cur);             
		}
		else if(cur==')')
		{
			if(s.empty() or s.top()!='(')         //empty means if 1st char is ")" then is false    or    if previous top char is not "("  for")"  then false
			{
				return false;
			}
			s.pop();                             //if a pair found "(" ==")"  then pop "("          ..condition found true...
		}
	}
	return s.empty();                      
}
int main()
{
	string expr;
	cin>>expr;
	cout<<checkexpression(expr);
//	cout<< isvalid;
	return 0;
}
