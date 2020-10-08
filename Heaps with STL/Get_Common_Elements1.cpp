#include <iostream>
#include<set>
using namespace std;
int main() 
{
    set<int> s1,s2;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s1.insert(a[i]);
    }
    int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
        s2.insert(b[i]);
    }
    for(auto p:s1)
    {
        for(auto q:s2)
        {
            if(p==q)
            {
                cout<<p<<endl;
            }
            
        }
    }
    
    
}

