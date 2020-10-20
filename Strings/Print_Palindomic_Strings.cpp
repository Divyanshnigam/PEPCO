#include <iostream>
#include<cstring>
using namespace std;
bool ispalindrome(string s)
{
	int i=0;
	int j=s.length()-1;
	while(i<=j)
	{
		if(s[i]!=s[j])
		{
			return false;
		}
		else
		{
			i++;
			j--;
		}
	}
	return true;
}
int main() 
{
    string s;
    cin>>s;
    
    for(int i=0;i<s.length();i++)
    {
        for(int j=1;j<=s.length()-i;j++)
        {
            string ss=s.substr(i,j);
            if(ispalindrome(ss)==true)
            {
            	cout<<ss<<endl;
			}
        }
    }
}
/*
Sample Input
abcc
Sample Output
a
b
c
cc
c
*/
