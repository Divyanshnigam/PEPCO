#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int q, n, v;
    vector<int> primes;
    primes.push_back(2);
    primes.push_back(3);
    for(int i = 5; i <= 10000; i++) //Sieve
    {
        int no = 0;
        for(int j = 2; j*j <= i; j++)
        {
            if(i%j == 0)
                no = 1;
        }
        if(!no)
            primes.push_back(i);
    }
    cin>>n>>q;
    stack<int> stack1, stack2, stack3;
    for(int i = 0 ; i < n; i++)
    {
        cin>>v;
        stack1.push(v);
    }
    for(int i = 0 ; i < q; i++)
    {
        if(stack1.empty())
            break;
        int cur = primes[i];
        while(!stack1.empty())
        {
            int ele = stack1.top();
            stack1.pop();
            if(ele%cur == 0)
            {
                stack2.push(ele);
            }
            else
            {
                stack3.push(ele);
            }
        }
        while(!stack2.empty())
        {
            cout<<stack2.top()<<endl;
            stack2.pop();
        }
        stack1 = stack3;
        while(!stack3.empty())
            stack3.pop();
    }
    while(!stack1.empty())
    {
        cout<<stack1.top()<<endl;
        stack1.pop();
    }
    return 0;
}
