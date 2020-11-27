#include<iostream>
#include<queue>
using namespace std;
int main()
{
	queue<char> q;
	int freq[27]={0};   //frequency table initialised woth zeros
	
	//running a stream until a '.'
	char ch;
	cin>>ch;
	while(ch!='.')
	{
	q.push(ch);         //push in the queue
	freq[ch-'a']++;     //'a'-'a'=0 _______ 'b'-'a'=1....  and at each frequency if the characters are repeating then incremented
	
	while(!q.empty())
	{
		int idx=q.front()-'a';    
		if(freq[idx]>1)      //if characters are repeating
		{
			q.pop();        //delete the previous element
		}
		else
		{
			cout<<q.front()<<endl;     //else print 
			break;
		}
	}
	//q is empty
	if(q.empty())           //after poping if no char available then print -1
	{
		cout<<"-1"<<endl;
	}
	cin>>ch;
    }
	return 0;
}
/*  i/p:
        aabccbc.
       
  o/p:
    a
    -1
    b
    b
    b
    -1
    -1
*/
