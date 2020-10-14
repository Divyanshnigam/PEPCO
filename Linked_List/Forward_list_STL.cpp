#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> l;
	list<int> l1{1,2,3,4,5};
	list<string>l2{"apple","guava","mango","banana"};
	l2.push_back("pineapple");
    l2.sort();
    l2.reverse();
    cout<<l2.front()<<endl;
    l2.push_front("kiwi");
  //  l2.pop_front();
    cout<<l2.back()<<endl;
    l2.pop_back();
    for(auto it=l2.begin();it!=l2.end();it++)
    {
        cout<<(*it)<<"->";
    }
    cout<<endl;
	for(string s:l2)
	{
		cout<<s<<"->";
	}
}
