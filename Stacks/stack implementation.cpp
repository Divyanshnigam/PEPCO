#include<iostream>
#include<vector>
using namespace std;
class stack
{
	private:
		vector<int> v;
	public:
		void push(int data)
		{
			v.push_back(data);
		}
		bool empty()
		{
			return v.size()==0;
		}
		void pop()
		{
			if(!empty())
			{
				v.pop_back();
			}
		}
		int top()
		{
			return v[v.size()-1];
		}
};
int main()
{
	stack s;
	for(int i=0;i<=5;i++)
	{
		s.push(i*i);
	}
	while(!s.empty())
	{
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;
}
