#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ozeros=1;
    int oones=1;
    int nzeros,nones;
    for(int i=2;i<=n;i++)
    {
        nzeros=oones;
        nones=oones+ozeros;

        oones=nones;
        ozeros=nzeros;
    }
    cout<<(nzeros+nones);
}
