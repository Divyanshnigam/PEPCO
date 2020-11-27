#include<iostream>
#include<stack>
using namespace std;

long long int getMaxArea(long long int hist[], long long int n)
{
    
    stack<long long int> s;
 
    long long int max_area = 0; 
    long long int tp;
    long long int area_with_top; 
                       
 
    long long int i = 0;
    for(long long int i=1;i<n;i++){
        
        
        while(!s.empty()&&hist[s.top()]>hist[i]){
            int top=s.top();
            s.pop(); 
            area_with_top=(s.empty())?hist[top]*i:hist[top]*(i-s.top()-1); 
            if(max_area<area_with_top)
            max_area=area_with_top;
        }
        s.push(i);
    }
    long long int size=s.size();
    while (s.empty() == false)
    {
        long long int top=s.top();
        s.pop();
        area_with_top=hist[top]*(size-s.size());
        if(max_area<area_with_top)
        max_area=area_with_top;
    }
 
    return max_area;
}
 
int main()
{
    long long int n;
    cin>>n;
    
    long long int hist[n];
    for(long long int i=0;i<n;i++){
        cin>>hist[i];
    }
    cout<<getMaxArea(hist, n);
}
