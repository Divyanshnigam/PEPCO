#include<iostream>
#include<list>
using namespace std;
int main() {
	list<int>l;
    int n;
	cin>>n;
	while(n--)
	{
		int k;
		cin>>k;
		l.push_back(k);
	}
	l.sort();
	for(int i :l)
	{
		cout<<i<<" ";
	}
	return 0;
}
