#include<iostream>
#include<bits/stdc++.h>
#include<set>
using namespace std;
void solution(string ustr,int cs,int ts,int lc,string asf)
{
    if(cs>ts)
    {
        cout<<asf<<endl;
        return;
    }
    for(int i=lc+1;i<ustr.length();i++)
    {
        char ch=ustr[i];
        solution(ustr,cs+1,ts,i,asf+ch);
    }
}
int main()
{
    string a;
    cin>>a;
    set <char> myset;
    string str ="";
    for(int i = 0 ; i < a.length() ; i++)
    {
        myset.insert(a[i]);
    }
    set<char,greater<char> >::iterator itr;
    for(itr = myset.begin() ; itr != myset.end() ; itr++)
    {
        str += *itr;
    }
    int k;
    cin>>k;
    solution(str,1,k,-1,"");
}
