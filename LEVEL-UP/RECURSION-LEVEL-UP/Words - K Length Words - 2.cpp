#include<iostream>
#include<bits/stdc++.h>
#include<set>
using namespace std;
void solution(int cs,int ts,string ustr,set<char>used,string asf)
{  
    if(cs>ts)
    {
        cout<<asf<<endl;
        return;
    }
    for(int i=0;i<ustr.length();i++)
    {
        char ch=ustr[i];
        if(used.count(ch)==0)
        {
            used.insert(ch);
            solution(cs+1,ts,ustr,used,asf+ch);
            used.erase(ch);
        }
    }
}
int main()
{
    string a;
    cin>>a;
    set <char> myset,used;
    string str ="";
    for(int i = 0 ; i < a.length() ; i++)
    {
        myset.insert(a[i]);
    }
    set<char>::iterator itr;
    for(itr = myset.begin() ; itr != myset.end() ; itr++)
    {
        str += *itr;
    }
    int k;
    cin>>k;    
    solution(1,k,str,used,"");
}
