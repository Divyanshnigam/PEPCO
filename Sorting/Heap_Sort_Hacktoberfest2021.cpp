#include <bits/stdc++.h>
using namespace std;
  
void heapify_smallest(int ar[], int n, int i) {
    //its to find smallest root among left nodes and right nodes 
    int smallest = i;
    int right = 2 * i + 2;
    int left = 2 * i + 1;
    
    if(right < n && ar[right] < ar[smallest])
      smallest = right;
    if(left < n && ar[left] < ar[smallest])
      smallest = left;
    if(smallest != i) {
      swap(ar[i], ar[smallest]);
      heapify_smallest(ar, n, smallest);   //using again same function
    }
  }
  
 
void Heap_Sort(int ar[],int n){
    for(int i = n / 2 - 1; i >= 0; i--)
      heapify_smallest(ar, n, i);

    for (int i = n - 1; i >= 0; i--){
      swap(ar[0], ar[i]);
  
      // Heapifying the root element to get lowest element at root again
    heapify_smallest(ar, i, 0);
    }
}
//Declaration
const int N=1e5+5;
long long p[N];
long long q[N];
int ar[N];

int main(){
    int n,i;
    cin >> n;
    int sum = 0;
    
    for(i = 0 ; i < n ; i++){
        cin >> ar[i];
        sum = sum + ar[i];   //sum of array
    }
    Heap_Sort(ar, n);  //sorting array using heap sort in descending order
    
    //Apply prefix sum algorithm to find sum of coins array
    p[0] = ar[0];
    for(int i = 1;i < n; ++i){    
       p[i] = p[i-1] + ar[i];
    }
    
    for(int i = 0;i <n; i++){  
       q[i] = sum - p[i];
    }
    
    for(int j = 0;j < n; ++j){
        if(p[j] > q[j]){
            cout << j+1;    //printing number of coins 
            break;
        }
    }
    
}

    
    
   

  
  

  
  

