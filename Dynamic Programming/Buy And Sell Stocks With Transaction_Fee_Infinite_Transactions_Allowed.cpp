#include<iostream>
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
    int fee;
    cin>>fee;
    int ob=-p[0];
    int os=0;
    for(int i=1;i<n;i++)
    {
        int nb=0;
        int ns=0;
        if(os-p[i]>ob)
        {
            nb=os-p[i];
        }
        else
        {
            nb=ob;
        }
        if(ob+p[i]-fee>os)
        {
            ns=ob+p[i]-fee;
        }
        else
        {
            ns=os;
        }
        os=ns;
        ob=nb;
    }
    cout<<os;
}
/*
Sample Input
12
10
15
17
20
16
18
22
20
22
20
23
25
3
Sample Output
13
*/
