#include <iostream>
#include <cstring>
using namespace std;
void queensCombinations(int qsf,int tot_queen,int row,int col,string asf)
{
    if(row==tot_queen)
    {
        if(qsf==tot_queen)
        {
            cout<<asf<<endl;
        }
        return;
    }
    int nr=0;
    int nc=0;
    string yasf="";
    string nasf="";
    if(col==tot_queen-1)
    {
        nr=row+1;
        nc=0;
        yasf=asf+"q\n";
        nasf=asf+"-\n";
    }
    else
    {
        nr=row;
        nc=col+1;
        yasf=asf+"q";
        nasf=asf+"-";
    }
    queensCombinations(qsf+1,tot_queen,nr,nc,yasf);
    queensCombinations(qsf+0,tot_queen,nr,nc,nasf);
}
int main() 
{
    int n;
    cin>>n;
    queensCombinations(0,n,0,0,"");
}

