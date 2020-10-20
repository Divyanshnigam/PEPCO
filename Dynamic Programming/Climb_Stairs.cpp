#include<iostream>
using namespace std;
int climb(int n,int *qb)  //memoisation
{
    if(n==0)
    {
        return 1;
    }
    else if(n<0)
    {
        return 0;
    }
    
    if(qb[n]>0)
    {
        return qb[n];
    }
    int w1=climb(n-1,qb);
    int w2=climb(n-2,qb);
    int w3=climb(n-3,qb);
    int w=w1+w2+w3;
    qb[n]=w;
    return w;
    
}
int climb_tabulation(int n)  //tabulation
{
    int qb[n+1];
    qb[0]=1;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            qb[i]=qb[i-1];
        }
        else if(i==2)
        {
            qb[i]=qb[i-1]+qb[i-2];
        }
        else
        {
            qb[i]=qb[i-1]+qb[i-2]+qb[i-3];
        }
    }
    return qb[n];
}
int main()
{
    int n;
    cin>>n;
    int qb[100]={0};
    cout<<climb(n,qb)<<endl;
    cout<<climb_tabulation(n);
    return 0;
    
}
