#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

    //A number is called almost prime if it has exactly two distinct prime divisors.
    //We need to find the amount of almost prime numbers which are between 1 and n, inclusive.
    
    //I am solving it Using Sieve of Eratosthenes Algorithm in c++
    
int main() {
    
    //Declaration
    int n,i,j;
    int No_of_almostprime;
    
    //Taking input of the number n 
    cin >> n;
    
    //solving it Using Sieve of Eratosthenes Algorithm in c++
    
    bool arr[3000] = {false};
    int count1[3000] = {0};
    
    
    for (i = 2; i <= n; i++){
        
        if(!arr[i]){
            
            for(j = i + i; j <= n ; j = j + i){
                arr[j] = true;
                count1[j] += 1;
            }
        }
        
        if(count1[i] == 2){
                
            No_of_almostprime += 1;
                
        }
           
        
    }
    
    //giving output of number of almost prime found
    cout << No_of_almostprime;
    return 0;
    
    
}

