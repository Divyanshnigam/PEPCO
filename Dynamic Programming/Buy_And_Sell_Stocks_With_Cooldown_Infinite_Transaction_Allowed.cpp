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
    int ob=-p[0];
    int os=0;
    int oc=0;
    for(int i=1;i<n;i++)
    {
        int nb=0;
        int ns=0;
        int nc=0;
        if(oc-p[i]>ob)
        {
            nb=oc-p[i];
        }
        else
        {
            nb=ob;
        }
        if(ob+p[i]>os)
        {
            ns=ob+p[i];
        }
        else
        {
            ns=os;
        }
        if(oc<os)
        {
            nc=os;
        }
        else
        {
            nc=oc;
        }
        os=ns;
        ob=nb;
        oc=nc;
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
Sample Output
19
*/
