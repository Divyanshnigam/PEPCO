#include<iostream>
using namespace std;
static int counter = 1; //Static variable
void solution(int i, int n, bool used[10], string asf)
{
    if(i > n)
    {
        cout<<counter<<"."<<asf<<endl;
        counter++;
        return;
    }
    if(used[i] == true)
    {
        solution(i+1,n,used,asf);
    }
    else
    {
        used[i] = true;
        solution(i+1,n,used,asf + "(" + to_string(i) + ") ");
        for(int j = i + 1 ; j <= n  ;j++)
        {
            if(used[j]== false)
            {
                used[j] = true;
                solution(i+1,n,used,asf + "(" + to_string(i) + "," + to_string(j) + ") ");
                used[j] = false;   
            }

        }
        used[i] = false;
    }
}
int main()
{
    int n;
    cin>>n;
    bool used [10] = {true};
    solution(1,n,used,"");
}
