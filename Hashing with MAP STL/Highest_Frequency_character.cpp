#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_map>
using namespace std;
int main()
{
    string key;
    cin>>key;
    unordered_map<char,int> M;
    for(int i = 0 ;  i < key.length() ; i++)
    {
         if (M.find(key[i]) == M.end()) { 
            M.insert(make_pair(key[i], 1)); 
        } 
  
        // Else update the frequency 
        else { 
            M[key[i]]++; 
        }
    }
    int max = 0;
    char ch;
    for (int i = 0 ; key[i] ; i++) 
    { 
        
        if(M[key[i]] > max)
        {
            max = M[key[i]];
            ch = key[i];  
        }  
    }
    cout<<ch;
    return 0;
}

//I/P: zmszeqxllzvheqwrofgcuntypejcxovtaqbnqyqlmrwitc
// O/P: q
