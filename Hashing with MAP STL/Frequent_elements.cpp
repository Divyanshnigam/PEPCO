#include<bits/stdc++.h>
using namespace std;
void printfre(vector<int> a, int n)
{
    unordered_map<int ,int >m;
    for(auto x: a)
    {
        m[x]++;
    }

    for(auto e:m)
    {
        cout<<e.first<<" "<<e.second<<endl;
    }

}
int main()
{
    vector<int> a{10,20,20,30,10};
    printfre(a,a.size());
}