#include <iostream>
#include<stack>
using namespace std;
void insert(stack<int> &s, int temp)
{
    if(temp>=s.top() or s.size()==0)
    {
        s.push(temp);
        return;
    }
    int var=s.top();
    s.pop();
    insert(s,temp);
    s.push(var);
    return;
}
void sort(stack<int> &s)
{
    if(s.size()==1)
    {
        return;
    }
    int temp=s.top();
    s.pop();
    sort(s);
    insert(s,temp);
    return;
}
int main() 
{
    stack<int> s;
    int t;
    for(int i=0;i<5;i++)
    {
        cin>>t;
        s.push(t);
    }
    sort(s);
    for(int i=0;i<5;i++)
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}

