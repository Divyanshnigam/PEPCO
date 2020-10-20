#include<iostream>
using namespace std;
int main()
{
    int f,c;
    cin>>f>>c;
    int in[f]={0};
    int ex[f]={0};
    int to[f]={0};
    in[2]=c;
    ex[2]=c*(c-1);
    to[2]=in[2]+ex[2];
    for(int i=3;i<=f;i++)
    {
        in[i]=ex[i-1];
        ex[i]=to[i-1]*(c-1);
        to[i]=ex[i]+in[i];
    }
    cout<<to[f]<<endl;
  /*  for(int i=1;i<=f;i++)
    {
        cout<<in[i]<<"    ";
    }
    cout<<endl;
    for(int i=1;i<=f;i++)
    {
        cout<<ex[i]<<"    ";
    }
    cout<<endl;
    for(int i=1;i<=f;i++)
    {
        cout<<to[i]<<"    ";
    }
    cout<<endl;  */
}
/*

Sample Input
8
3
Sample Output
3672
*/
