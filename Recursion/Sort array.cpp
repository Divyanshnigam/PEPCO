#include <iostream>
#include<vector>
using namespace std;
void insert(vector<int> &v,int temp)
{
    if(v[v.size()-1]<=temp or v.size()==0)
    {
        v.push_back(temp);
        return;
    }
    int val=v[v.size()-1];
    v.pop_back();
    insert(v,temp);
    v.push_back(val);
    return;
}
void sort(vector<int> &v)
{
    if(v.size()==1)
    {
        return;
    }
    int temp=v[v.size()-1];
    v.pop_back();
    sort(v);
    insert(v,temp);
    return;
}
int main() 
{
    vector<int> v={1,5,2,0,};
    sort(v);
    for(auto it:v)
    {
        cout<<it<<" ";
    }
}
