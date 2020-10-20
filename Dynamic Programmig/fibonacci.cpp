#include<iostream>
using namespace std;
int fiborec(long int n)
{
    if(n==0||n==1)
      return n;
    else
      return fiborec(n-1)+fiborec(n-2);
}
int TopToDownDP(long int n,long int *a)
{
   if(n==1||n==0)
     a[n]=n;
     return n;
   if(n!=-1)
    return a[n];
   else
   {
       a[n]=TopToDownDP(n-1,a)+TopToDownDP(n-2,a);
       return a[n];
   }
   
}
int BottomToUpDP(long int n)
{
   long int *da = new long int[n];
   da[0]=0;
   da[1]=1;

   for(long int i=2;i<=n;i++)
   {
       da[i]=da[i-1]+da[i-2];
   }
   return da[n];
      
}
int main()
{
  long int n,a[100];
  for(int i=0;i<100;i++)
     a[i]=-1;
  cout<<"Enter the index of fibonacci you want to print : ";
  cin>>n;
  cout<<"The answer is : "<< fiborec(n)<<endl;
  cout<<"The answer is : "<<BottomToUpDP(n)<<endl;
  return 0;
}
