#include <iostream>
using namespace std;
int main() 
{
    int so=0;
    string s="101000010101";
    int count1=0,count0=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')
            count1++;
        else if(s[i]=='0')
            count0++;
    }
    int l=0,r=s.size()-1;
    while(l<r)
    {
        if(count1>count0)
        {

        }
    }
}
