#include <algorithm> 
#include <iostream> 
#include <vector> 
using namespace std; 
  
void countSort(vector<int>& arr)    //  3 3 7 9 4 8 6 1 5 9 9 4 9
{ 
    int max = *max_element(arr.begin(), arr.end());   // taken max element out of array ==9
    int min = *min_element(arr.begin(), arr.end());   // taken min element out of array ==3
    int range = max - min + 1;       // ==9 - 3 + 1 ==7 i.e. 7 different elements are there in btw 3 to 9
  
    vector<int> count(range), output(arr.size()); 
    for (int i = 0; i < arr.size(); i++) 
        count[arr[i] - min]++;                // created the frequency table
  
    for (int i = 1; i < count.size(); i++) 
        count[i] += count[i - 1];         // Modify the count array such that each element at each index stores the sum of previous counts
  
  // Output each object from the input sequence followed by decreasing its count by 1.
    for (int i = arr.size() - 1; i >= 0; i--) 
	{ 
        output[count[arr[i] - min] - 1] = arr[i];  // assigning each element to a index
        count[arr[i] - min]--;      // decreasing the freq..
    } 
  
    for (int i = 0; i < arr.size(); i++) 
        arr[i] = output[i]; 
} 
  
void printArray(vector<int>& arr) 
{ 
    for (int i = 0; i < arr.size(); i++) 
        cout << arr[i] <<endl; 
    cout <<endl; 
} 
  
int main() 
{ 
    int n,data;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
    	cin>>data;
    	arr.push_back(data);
	}
	countSort(arr); 
    printArray(arr); 
    return 0; 
} 
