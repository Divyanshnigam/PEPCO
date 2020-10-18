#include<iostream>
#include <math.h>
#include<string.h>

using namespace std;

class stack{
	int top;
	char st[20];
    int MAXSIZE=20;

	public:
	void push(char d[]);
	char[] pop();
	int isempty();
	int isfull();
	void display();

	stack()
	{
		top=-1;
	}
};

	int stack::isempty()
	{
		if(top==-1)
			return 1;
		return 0;
	}
	int stack::isfull()
	{
		if(top==MAXSIZE-1)
			return 1;
		return 0;
	}
	void stack::push(char ch[])
	{
	   if(isfull()==0)
       {
          top++;
          st[top]=ch;
       }
       else
            cout<<"Stack is full!"<<endl;

	}
	char[] stack::pop()
	{
		char data;
		if(isempty()==0)
		{
			data=st[top];
			top--;
			return data;
		}
		else
			return '#';
	}

int main() {

        stack s;
		char postfix[20];
		char s1[20];
		char temp[20];
		int i=0;
		char ch,s2,s3;


		cout<<"Enter the postfix expression:"<<endl;
		cin>>postfix;

		while(postfix[i]!='\0')
		{
		    ch=postfix[i];
			i++;

		    s1[0]=ch;
		    s1[1]='\0';

			if(ch>='a'&&ch<='z')
			{
				s.push(s1);
			}
			else
			{
				s2=s.pop();
				s3=s.pop();

				strcpy(temp,"(");
				strcat(temp,s3);
				strcat(temp,s1);
				strcat(temp,s2);
				strcat(temp,")");

				s.push(temp);
			}
		}
		cout<<"Infix Expression: "<<temp;
}
