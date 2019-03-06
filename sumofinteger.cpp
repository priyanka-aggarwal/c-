#include<iostream>
#include<stdlib.h>
using namespace std;

template<class t>
class stack
{
	int size,top;
	t *A;
	public:
		stack()
		{
			top=-1;
			size=10;
			A=new t[size];
		}
		stack(int s)
		{
			top=-1;
			size=s;
			A=new t[size];
		}
		void push(t &x);
		t pop();
		void show();
};

template<class t>
void stack<t>::push(t &x)
{
	if(top==size-1)
	{
		cout<<"\n Stack is overflow \n";
		exit(1);
	}
	top++;
	A[top]=x;
}


template<class t>
t stack<t>::pop()
{
	if(top==-1)
	{
		cout<<"\n Stack is underflow \n";
	}
	t x;
	x=A[top];
	top--;
	return x;
}

int main()
{
	char a1[10],a2[10];
	int b1[10],b2[10],b3[10],carr=0;
	int c=0,d=0;
	cout<<"Enter first integer"<<"\t";
	gets(a1);
	cout<<"Enter second integer"<<"\t";
	gets(a2);
	for(int i=0;a1[i]!='\0';i++)
	{
		if(a1[i]=='0' || a1[i]=='1' ||a1[i]=='2' ||a1[i]=='3' ||a1[i]=='4' ||a1[i]=='5' ||a1[i]=='6' ||a1[i]=='7' ||a1[i]=='8' ||a1[i]=='9' )
		    c++;
	} 
	for(int i=0;a2[i]!='\0';i++)
	{
		if(a2[i]=='0' || a2[i]=='1' ||a2[i]=='2' ||a2[i]=='3' ||a2[i]=='4' ||a2[i]=='5' ||a2[i]=='6' ||a2[i]=='7' ||a2[i]=='8' ||a2[i]=='9' )
		    d++;
	} 
	stack <char>o1(c);
	stack <char>o2(d);
	for(int i=0;i<c;i++)
	{
		if(a1[i]=='0' || a1[i]=='1' ||a1[i]=='2' ||a1[i]=='3' ||a1[i]=='4' ||a1[i]=='5' ||a1[i]=='6' ||a1[i]=='7' ||a1[i]=='8' ||a1[i]=='9' )
		o1.push(a1[i]);
	}
		for(int i=0;i<d;i++)
	{
		if(a2[i]=='0' || a2[i]=='1' ||a2[i]=='2' ||a2[i]=='3' ||a2[i]=='4' ||a2[i]=='5' ||a2[i]=='6' ||a2[i]=='7' ||a2[i]=='8' ||a2[i]=='9' )
		o2.push(a2[i]);
	}
   cout<<"\n THE POPPED FIRST ELEMENT ="; 	
	for(int i=0;i<c;i++)
	{
	     b1[i]=o1.pop()-'0';
	   cout<<b1[i];
    }
    int e=0,i=0;
	 cout<<"\n THE POPPED SECOND ELEMENT =";  
	for(i=0;i<d;i++)
	{
	   b2[i]=o2.pop()-'0';
	   cout<<b2[i];
    }
		for(int i=0;(i<c||i<d);i++)
		{
			if(i>=c)
			  b1[i]=0;
			if(i>=d)
			  b2[i]=0;
			b3[i]=b1[i]+b2[i]+carr;
			
			if(b3[i]>9)
			{
				carr=b3[i]/10;
				b3[i]=b3[i]%10;
			}
			else
			   carr=0;
			   e++;
		}
		b3[++i]=carr;
		++e;
		stack <int>o3(e);
		for( i=0;i<e;i++)
		 o3.push(b3[i]);
		 cout<<"\n the sum =";
        for( i=0;i<e;i++)	
		 {
		  int  z=o3.pop();
		   cout<<z;	 
	     }
	     cout<<endl;
	     system("pause");
	     return 0;
}
