#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    //cout<<n;
    int a=0;
    int ab=0;
    int abc=0;
    for(int i=0;i<n+1;i++)
    {
        char ch=s[i];
        if(ch=='a')
        {
            a=2*a+1;
        }
        else if(ch=='b')
        {
            ab=2*ab+a;
        }
        else if(ch=='c')
        {
            abc=2*abc+ab;
        }
    }
    cout<<abc;
}
/*
Sample Input
abcabc
Sample Output
7
*/
