#include <iostream>
#include<cstring>
using namespace std;
void print(char a[][10])
{
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool can_place_word_vertically(char a[][10],string word,int i,int j)
{
    if(i-1>=0 and a[i-1][j]!='+')  // left side is there and anything else +
    {
        return false;
    }
    else if(i+word.length()<10 and a[i+word.length()][j]!='+')
    {
        return false;
    }
    // perfect fit
    for(int ii=0;ii<word.length();ii++)
    {
        if(i+ii >=10)   // if word out of limit
        {
            return false;
        }
        if(a[i+ii][j]=='-' or a[i+ii][j]==word[ii])
        {
            continue;   // if there's a dash or the wanted word
        }
        else
        {
            return false;
        }
    }
    return true;
}
bool can_place_word_horizontally(char a[][10],string word,int i,int j)
{
    if(j-1>=0 and a[i][j-1]!='+')  // left side is there and anything else +
    {
        return false;
    }
    else if(j+word.length()<10 and a[i][j+word.length()]!='+')
    {
        return false;
    }
    // perfect fit
    for(int jj=0;jj<word.length();jj++)
    {
        if(j+jj >=10)   // if word out of limit
        {
            return false;
        }
        if(a[i][j+jj]=='-' or a[i][j+jj]==word[jj])
        {
            continue;   // if there's a dash or the wanted word
        }
        else
        {
            return false;
        }
    }
    return true;
}
bool place_word_horizontally(char a[][10],string word,int i,int j)
{
    bool we_placed[word.length()];
    for (int jj=0;jj<word.length();jj++)
    {
        if(a[i][j+jj]=='-')
        {
            a[i][j+jj]=word[jj];
            we_placed[jj]=true;
        }
    }
    return we_placed;
}
bool place_word_vertically(char a[][10],string word,int i,int j)
{
    bool we_placed[word.length()];
    for (int ii=0;ii<word.length();ii++)
    {
        if(a[i+ii][j]=='-')
        {
            a[i+ii][j]=word[ii];
            we_placed[ii]=true;
        }
    }
    return we_placed;
}
void unplace_horizontally(char a[][10],bool we_placed,int i,int j)
{
    for (int jj=0;jj<we_placed.length();jj++)
    {
        if(we_placed[jj]==true)
        {
            a[i][j+jj]='-';
        }
    }
}
void unplace_vertically(char a[][10],bool we_placed,int i,int j)
{
    for (int ii=0;ii<we_placed.length();ii++)
    {
        if(we_placed[ii]==true)
        {
            a[i+ii][j]='-';
        }
    }
}
void solution(char a[][10],string words[],int vidx)
{
    // base case
    if(vidx==10)
    {
        print(a);
        return;
    }


    string word=words[vidx];  //to try this 1 word 
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)  //having 100*2 option verti and horizon
        {
            if(a[i][j]=='-' or a[i][j]==word[0])
            {
                //horizontally
                if(can_place_word_horizontally(a,word,i,j))
                {
                    bool we_placed= place_word_horizontally(a,word,i,j); //pre
                    solution(a,words,vidx+1);
                    unplace_horizontally(a,we_placed,i,j);  //post  to undo for 2nd choise
                }
                // VERTICALLY
                if(can_place_word_vertically(a,word,i,j))
                {
                    bool we_placed= place_word_vertically(a,word,i,j); //pre
                    solution(a,words,vidx+1);
                    unplace_vertically(a,we_placed,i,j);  //post  to undo for 2nd choise
                }
            }
        }
    }
}
int main() 
{
    char a[10][10];
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cin>>a[i][j];
        }
    }
    int n;
    cin>>n;
    string words[n];
    for (int i=0;i<n;i++)
    {
        cin>>words[i];
    }
    solution(a,words,0);
}

