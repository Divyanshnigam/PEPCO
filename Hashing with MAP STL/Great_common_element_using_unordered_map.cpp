#include<iostream>
#include<unordered_map>
using namespace std;

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++) cin>>arr[i];

    int m;
    cin>>m;
    int arr2[m];
    for(int i = 0 ; i < m ; i++) cin>>arr2[i];

    unordered_map<int,int> umap;

    for(int i = 0 ; i < n ; i++){
        umap[arr[i]]++;
    }

    for(int i = 0 ; i < m ; i++){
        if(umap.find(arr2[i]) == umap.end()){

        }
        else{
            cout<<arr2[i]<<endl;
            umap.erase(arr2[i]);
        }
    }
    return 0;
}

//Here we used the technique of unordered map, just because of the fact that set orders the element in the ascending order. 
