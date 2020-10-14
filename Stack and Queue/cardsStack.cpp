#include <iostream>
#include<stack>

using namespace std;

bool isPrime(int n) 
{  
    if (n <= 1) 
        return false; 
  
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 

int main()
{

	 	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

   stack<int> s1;
   stack<int> s2;

   int n,m,a;
   cin>>n>>m;
   while(m--){

   for(int i = 0;i<n;i++){

   	cin>>a;
   	if(isPrime(a)){
   		s1.push(a);
   	}
   	else{
   		s2.push(a);
   	}

   }

}
	while(!s2.empty()){
		cout<<s2.top()<<endl;
		s2.pop();
	}
		while(!s1.empty()){
		cout<<s1.top()<<endl;
		s1.pop();
	}

}