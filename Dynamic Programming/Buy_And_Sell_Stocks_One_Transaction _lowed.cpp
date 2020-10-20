#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int p[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    int lsf=INT_MAX;
    int op=0;
    int cp=0;
    for(int i=0;i<n;i++)
    {
        
        if(p[i]<lsf)
        {
            lsf=p[i];
        }
        cp=p[i]-lsf;
        if(cp>op)
        {
            op=cp;
        }
    }
    cout<<op;
}
/*
Sample Input
9
11
6
7
19
4
1
6
18
4
Sample Output
17
*/
