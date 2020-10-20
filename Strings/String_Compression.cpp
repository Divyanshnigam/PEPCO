#include <iostream>
#include<cstring>
using namespace std;
int main() 
{
    string s;
    cin>>s;
    for(int i=1;i<s.length();i++)
    {
    	if(s[i]!=s[i-1])
    	{
    		cout<<s[i-1];
		}
	}
	cout<<s[s.length()-1];
	cout<<endl;
	int count=1;
	for(int i=1;i<s.length();i++)//  aaabbcccde  a3b2c3d1e
	{
		
		if(s[i]==s[i-1])
		{
			count+=1;
		}
		else
		{
			cout<<s[i-1];
			if(count>1)
			{
				cout<<count;
			}
			count=1;
		}
	}
	cout<<s[s.length()-1];
	if(count>1)
	{
		cout<<count;
	}
}
/*
Sample Input
wwwwaaadexxxxxx

Sample Output
wadex
w4a3dex6
*/
