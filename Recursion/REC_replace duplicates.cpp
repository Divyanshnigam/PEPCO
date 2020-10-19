#include <iostream>

using namespace std;
void replaceConsicutiveDuplicates(char *input)
{
    if(input[0]=='\0')
        return;
    if(input[0]==input[1])
    {
        for(int i=1;input[i]!='\0';i++)
            input[i]=input[i+1];
        return replaceConsicutiveDuplicates(input);
    }
    else
        replaceConsicutiveDuplicates(input+1);
}

int main()
{
    char str[20];
    cin>>str;
    replaceConsicutiveDuplicates(str);
    cout<<str<<endl;
}
