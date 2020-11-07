#include <iostream>
#include <cstring>
using namespace std;
void solve(int *a,int n,int total,string asf,int sum,int i)
{
    if(i==n)
    {
        if(sum==total)
        {
            cout<<asf<<"."<<endl;
        }
        return;
    }
    solve(a,n,total,asf + to_string(a[i]) + "-" ,sum+a[i],i+1);
    solve(a,n,total,asf ,sum,i+1);    
   
}
int main() 
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int total;
    cin>>total;
    solve(a,n,total,"",0,0);
}

