#include<iostream>
using namespace std;
int fibonacci(int n,int *qb)  //memoised
{
    if(n==0 or n==1)
    {
        return n;
    }
    if(qb[n]!=0)
    {
        return qb[n];
    }
    int f1=fibonacci(n-1,qb);
    int f2=fibonacci(n-2,qb);
    int fib=f1+f2;
    qb[n]=fib;
    return fib;
}
int main()
{
    int n;
    cin>>n;
    int qb[100]={0};
    cout<<fibonacci(n,qb);
    return 0;
}
