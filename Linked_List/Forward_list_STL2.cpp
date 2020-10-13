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
    l2.push_back("orange");
    l2.push_back("lemon");
    //remove a fruit by value
    string f;
    cin>>f;
    l2.remove(f);
    // or else like
    l2.remove("mango");
    //removing 3rd element
    auto it=l2.begin();
    it++;
    it++;
    l2.erase(it);
    //insert
    it=l2.begin();
    it++;
    l2.insert(it,"fruit juice");
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
