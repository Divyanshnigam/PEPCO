#include<bits/stdc++.h>
using namespace std;
void printfre(vector<int> a, int n)
{
    for(int i=0;i<n;i++)
    {
        bool flag =false;
        for(int j=0;j<i;i++)
        {
            if(a[i]==a[j])
            {
                flag=true;
                break;
            }
        }
        if(flag==true)
        {
            continue;
        }
        int freq=1;
        for(int j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
                freq++;
        }
        cout<<a[i]<<" "<<freq<<endl;
    }
}
int main()
{
    vector<int> a{10,20,20,30,40};
    printfre(a,a.size());
}