#include<iostream>
using namespace std;
int main()
{
    int r,c;
    cin>>r>>c;
    int arr[r][c];
    for(int i = 0 ; i< r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            cin>>arr[i][j]; //input of an array 
        }
    }
    int dir = 0 ; //it is moving in west 
    int i = 0 ;
    int j = 0;
    /* dir = 0[e]
    dir = 1[s] ; dir = 2[w] ; dir = 3[n] ; dir = 0[again back to east]*/
    while(true)
    {
        dir = (dir + arr[i][j] ) % 4;
        if(dir == 0) //east 
        {
            j++;
        }
        else if(dir == 1) //south
        {
            i++;
        }
        else if(dir == 2) //west 
        {
            j--;
        }
        else if(dir == 3) //north 
        {
            i--;
        }
        
        //Exit point condition
        if( i < 0)
        {
            i++;
            break;
        }
        else if(j < 0)
        {
            j++;
            break;
        }
        else if(i == r)
        {
            i--;
            break;
        }
        else if(j == c)
        {
            j--;
            break;
        }
    }
    cout<<i<<endl<<j;
}
/*
Sample Input
4
4
0
0
1
0
1
0
0
0
0
0
0
0
1
0
1
0
Sample Output
1
3
*/
