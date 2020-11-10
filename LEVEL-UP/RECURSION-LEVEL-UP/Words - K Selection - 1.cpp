#include<iostream>
#include<bits/stdc++.h>
#include<set>
using namespace std;
void solution(int i, string str, int pos, int k, string asf)
{
    if(i == str.length())
    {
        if(pos == k)
        {
            cout<<asf<<endl;
        }
        return;
    }
    char ch = str[i];
    solution(i+1,str,pos+1,k,asf+ch);
    solution(i+1,str,pos+0,k,asf+"");
    
   
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
    solution(0,str,0,k,"");
}
