#include<bits/stdc++.h>
using namespace std;
int main()
{
    int res=-1;
    string s="leetcode";
    bool visited[256]={false};
    for(int i=s.size()-1;i>=0;i--)
    {
        if(visited[s[i]]==false) // if not repeated set true..
            visited[s[i]]=true;
            // if repeated store its index
            res=i;
    }
    cout<<res;
    
}