#include<bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) 
{
    int i=0;
    int j=0;
    vector<long long> ans;
    queue<long long> list;
    while(j<N)
    {
        if(A[j]<0)
        {
            list.push(A[j]);
        }
        if((j-i+1)<K)
        {
            
            j++;
        }
        else if((j-i+1) == K)
        {
            
            // calcuation 
            if(list.size()==0)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(list.front());
                //slide
                
            }
            if(A[i]==list.front())
            {
                list.pop();
            }
            i++;
            j++;
            // if(A[j]<0)
            // {
            //     list.push(A[j]);
            // }
            
        }
    }
    return ans;
}
int main()
{
    // printFirstNegativeInteger();.....
}