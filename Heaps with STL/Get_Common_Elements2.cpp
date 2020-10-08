#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
  //  pair<int,int> p;
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++) cin>>arr[i];

    int m;
    cin>>m;
    int arr2[m];
    for(int i = 0 ; i < m ; i++) cin>>arr2[i];

    unordered_map<int,int> count;
    // vector<int> a;

    for (int i = 0; i < n ; i++) {
            if (count.find(arr[i]) == count.end()) {
                count[arr[i]] = 1;
            } else {
                count[arr[i]]++;
            }
        }

    for(int i = 0 ; i < m ; i++){
            if (count.find(arr2[i]) != count.end()) {
                if (count[arr2[i]] > 0) {
                    // a.push_back(arr[i]);
                    cout<<arr2[i]<<endl;
                    count[arr2[i]] --;
                }
            }
    }

// for (auto it = a.begin(); it != a.end() ; it++)
// {
//             cout << *it << " "; 
// }


    return 0;

}
