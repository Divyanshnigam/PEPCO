#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
bool checkexpr(string str)
{
	stack<char>s;
	for(int i=0;i<str.size();i++)
	{
	
		char cur=str[i];
		if(cur=='(' or cur=='[' or cur=='{')
		{
			s.push(cur);
		}
		else if(cur==')')
		{
			if(s.empty() or s.top()!='(')
			{
				return false;
			}
			s.pop();
		}
		else if(cur==']')
		{
			if(s.empty() or s.top()!='[')
			{
				return false;
			}
			s.pop();
		}
		else if(cur=='}')
		{
			if(s.empty() or s.top()!='{')
			{
				return false;
			}
			s.pop();
		}
	}
/*	if(s.empty()){
		return true;
	}
	else{
		return false;
	}*/
	return s.empty();
}
int main() 
{
	string expr;
	cin>>expr;
    int isvalid=checkexpr(expr);    

	if(isvalid==1)
	{
		cout<<"Yes";
	}
	else if(isvalid==0)
	{
	cout<<"No";
    }
	return 0;
}
