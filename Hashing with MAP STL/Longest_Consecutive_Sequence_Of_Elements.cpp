#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	unordered_map<int,bool> m;
    for(int i=0;i<n;i++)
    {
        m.insert(pair<int ,bool>(a[i],true));
    }
    for(int i=0;i<n;i++)
    {
        if(m.find(a[i]-1)!=m.end())
        {
            m.at(a[i])=false;
        }
    }

    int msp=0;
    int ml=0;
    for(int i=0;i<n;i++)
    {
        if(m.at(a[i]) == true){
            int tl = 1;
            int tsp = a[i];
            while(m.find(tsp + tl) != m.end()){
                tl++;
            }

            if(tl > ml){
                ml = tl;
                msp = tsp;
            }

        }

    }
    for(int i = 0 ; i < ml ; i++){
        cout<<msp+i<<endl;
    }

return 0;
}
