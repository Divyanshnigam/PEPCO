#include<iostream>
#include<string>
using namespace std;
void print(string str,string asf,int count,int pos)
{
	if(pos==str.length())
	{
		if(count==0)
		{
			cout<<asf<<endl;
		}
		else
		{
			cout<<(asf+to_string(count))<<endl;
		}
		return;
	}
	if(count>0)
	{
		print(str,(asf+to_string(count)+str[pos]),0,pos+1);  // yes 
	}
	else
	{
		print(str,asf+str[pos],0,pos+1);  // no
	}
	print(str,asf,count+1,pos+1);
}
int main()
{
	string str;
	cin>>str;
	print(str,"",0,0);
}
/*
Sample Input
pep
Sample Output
pep
pe1
p1p
p2
1ep
1e1
2p
3
*/
