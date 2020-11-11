#include <iostream>
#include<vector>
using namespace std;
static int counter=0;
void solution(int i, int n, int k, int nos, vector<int> ans) 
{		
    if(i>n)
    {
        if(nos==k)
        {
            counter++;
            cout<<counter<<", ";
            for(auto set: ans)
            {
                cout<<set<<" ";
            }
            cout<<endl;
        }
        return;
    }
    for(int j=0;j<k;j++)  // for each partition
    {
        if(!ans[j].empty()) //if the part is not empty 
        {
            ans[j].push_back(i);
            solution(i+1,n,k,nos,ans);   // adding in the same partion
            ans[j].pop_back(i);
        }
        else
        {
            ans[j].push_back(i);
            solution(i+1,n,k,nos+1,ans);  //// adding in the different partion
            ans[j].pop_back(i);
            break;   //just not to repeat the same!!permutation!!..
        }
    }
}
int main() {
    int n;
    int k;
    vector<int> ans;   
    solution(1, n, k, 0, ans);
}
