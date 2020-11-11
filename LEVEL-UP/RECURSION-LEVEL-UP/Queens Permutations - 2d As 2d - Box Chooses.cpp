#include <iostream>
#include <cstring>
using namespace std;
void queensPermutations(int qsf,int tq,int row,int col,string asf,bool *queens)
{
    if(row==tq)
    {
        if(qsf==tq)
        {
            cout<<asf<<endl;
            cout<<endl;
        }
        return ;
    }
    int nr=0;
    int nc=0;
    string sep=" ";
    
    if(col==tq-1)
    {
        nr=row+1;
        nc=0;
        sep="\n";
    }
    else
    {
        nr=row;
        nc=col+1;
        sep="\t";
    }
    for(int i=0;i<tq;i++)
    {
        if(queens[i]==false)
        {
            queens[i]=true;
            queensPermutations(qsf+1,tq,nr,nc,asf+"q"+ to_string(i+1)+ sep,queens);
            queens[i]=false;
        }    
    }
    queensPermutations(qsf,tq,nr,nc,asf+"-"+sep,queens);
}

int main() 
{
    int n;
    cin>>n;
    bool queens[n] = {false}; //this will help you to have false at every location in the array, else it will have a garbage value. So, we need to declare false everywhere
    queensPermutations(0,n,0,0,"",queens);
}

