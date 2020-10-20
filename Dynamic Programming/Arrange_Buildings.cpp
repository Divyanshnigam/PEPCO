#include<iostream>
using namespace std;
int main()
{
    long int n;
    cin>>n;
    long int os=1;
    long int ob=1;
    long int ns,nb;
    for(long int i=2;i<=n;i++)
    {
        ns=ob;
        nb=ob+os;

        ob=nb;
        os=ns;
    }
    long int total=(ns+nb);
    cout<<(total*total);
}
/*
Arrange Buildings


Question
1. You are given a number n, which represents the length of a road. The road has n plots on it's each side.
2. The road is to be so planned that there should not be consecutive buildings on either side of the road.
3. You are required to find and print the number of ways in which the buildings can be built on both side of roads.

Sample Input
6
Sample Output
441
*/
