#include<iostream>
#include<stdlib.h>
using namespace std;
class stack
{
	char A[10];
	int top,size;
	public:
		stack()
		{
			top=-1;
			size=4;
		}
	   stack(int l)
	   {
	   	 top=-1;
	   	 size=l;
	   }
	   void push(char);
	   char pop();	
	   void show();
};
void stack::push(char a)
{
    if(top==size-1)
	{
		cout<<"stack is overflow";
		exit(1);
	} 	
	top++;
	A[top]=a;
}
char stack::pop()
{
	if(top==-1)
	{
		cout<<"stack is underflow";
		exit(1);
	}
	char b;
	b=A[top];
	top--;
	return b;
}
void stack::show()
{
	if(top==-1)
	{
		cout<<"stack is underflow";
		exit(1);
	}
	cout<<"expression you entered : \n";
	for(int i=0;i<size;i++)
	{
		cout<<A[i];
	}
}
int main()
{
	 int flag=1;
	char q[20],w[10],a;
	int c=0,d=0;
	cout<<"enter expression =";
    gets(q);
	for(int i=0;q[i]!='\0';i++)
	{
        if(q[i]=='{' || q[i]=='[' || q[i]=='(')
		       c++;
	    if(q[i]=='}' || q[i]==']' || q[i]==')')
                d++;    	 
    }
    if(c!=d)
         {
			 flag=0;
			 cout<<"Not correctly paranthesised \n";
			 system("pause");
			 exit(0);
		 }
   stack s(c);
  
   for(int i=0;q[i]!='\0';i++)
    {
      if(q[i]=='{' || q[i]=='[' ||q[i]=='(')
	 	s.push(q[i]);
	   if(q[i]=='}' || q[i]==']' || q[i]==')')
	   {
	   		a=s.pop();
	   		if(a=='(')
	   		 a=')';
	   		else if(a=='{')
	   		 a='}';
	   		else if(a=='[')
	   		 a=']';
	   	    if(q[i]!=a)
	   	    {
			 flag=0;
			 cout<<"Not correctly paranthesised at"<<i;
			 system("pause");
			 exit(0);
		   }
	   }
	 	
    }
   
            
	if(flag==0)
	cout<<"not correctly paranthesised\n";
	else
	cout<<"correctly paranthesised\n";
	system("pause");
	return 0;
}
	

