#include<iostream>
#include<cstring>
using namespace std;
bool isPallindromic(string str)
{
    int li=0;
    int ri=str.length()-1;
    while(li<ri)
    {
        char left=str[li];
        char right=str[ri];
        if(left != right)
        {
            return false;
        }
        li++;
        ri--;
    }
    return true;
}
void solution(string str, string asf) 
{
    if(str.length()==0)
    {
        cout<<asf<<endl;
        return;
    }
    for(int i=0;i<str.length();i++)
    {
        string prefix=str.substr(0,i+1);
        string ros=str.substr(i+1);
        if(isPallindromic(prefix))
        {
            solution(ros,asf+"(" + prefix + ") ");
        }
    }
}

int main()
{
    string str;
    cin>>str;
    solution(str, "");
    return 0;
}
