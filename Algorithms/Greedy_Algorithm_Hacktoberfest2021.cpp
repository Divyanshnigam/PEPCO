#include <iostream>
using namespace std;

            //solved this question using Greedy Algorithm
int main(){
    //Declaration
    int t;
    
    //Taking input of number of test cases
    cin>>t;
    
    for(int i = 0; i < t; ++i){
        int n;      
        cin>>n;    //taking input of number of elements in password array for different test cases
        
        long long int *pass_arr = new long long int[n];
        
        //Taking input of every elements of initial password array
        for(int j = 0; j < n; ++j){
            cin>>pass_arr[j];
        }
        
        int count = 1;
        for(int j = 1; j < n; j++){
            if(pass_arr[j] == pass_arr[0]){
                count++;
            }
        }
        
        //Printing length of password
        if(count == n){
            cout << n << endl;
        }
        else{
            cout << 1 << endl;
        }
    }
    
    return 0;
}

