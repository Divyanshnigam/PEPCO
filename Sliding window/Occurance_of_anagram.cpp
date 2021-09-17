#include<bits/stdc++.h>
using namespace std;
vector<int> search_anagrams(string s,string p)
{
    // map of pattern string containing all char with count..
    unordered_map<char,int>m;
    for(auto i:p)
        m[i];  // if @ 0 'a' then m[i]=a

}
int main()
{
    string s="cbaebabacd";
    string p="abc";
    search_anagrams(s,p);
}