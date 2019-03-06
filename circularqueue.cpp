#include<iostream>
#include<stdlib.h>
using namespace std;
template <class t>
class cirqueue
{
	t*A;
	int last,first,size;
	public:
		cirqueue()
		{
			size=10;
			A=new int[size];
			first=last=-1;
		}
		cirqueue(int s)
		{
			size=s;
			A=new t[size];
			first=last=-1;
		}
		void enqueue(t x);
		t dequeue();
		void show();
};

template<class t>
void cirqueue<t>::show()
{   
    if(first==-1)
      cout<<"\n Queue is empty \n";
      else if(last>=first)
	  {
           	cout<<" \n \n Queue is \t";
	        for(int i=first;i<=last;i++)
	             cout<<A[i]<<"\t";
      }
      else
      {
      	for(int i=first;i<size;i++)
      	  cout<<A[i]<<"\t";
      	for(int i=0;i<=last;i++)  
      	  cout<<A[i]<<"\t";
	  }
}

template<class t>
void cirqueue<t>::enqueue(t x)
{
	if(((first==0) && (last==size-1)) || (first==last+1))
	    {
	       cout<<"\n Queue is overflow \n";
	       exit(1);
	    }
	if(first==-1)
	   {
	   	  first=last=0;
	   	  A[first]=x;
	   } 
	else if(last==size-1)
	   {
	   	last=0;
	   	  A[last]=x;
	   } 
	else
	{
		last++;
		A[last]=x;
	}   	    
}

template<class t>
t cirqueue<t>::dequeue()
{
	t x;
	if(first==-1)
	{
		cout<<"\n Queue is underflow \n";
		exit(1);
	}
	if(first==last)
	{
	   x=A[first];
	   first=last=-1;	
	}
	else if(first==size-1)
	{
		x=A[first];
		first=0;
	}
	else
	  {
	  	 x=A[first];
	  	 first++;
	  }
	return x;
}

int main()
{
	int c1,c2,size;
	char x,r;
	char w;
	cout<<"\n Enter the size of queue \t ";
	cin>>size;
	cirqueue <char> q(size);
	do
	{
	cout<<"\n \n Main Menu \n"<<" 1.Enter in queue"<<"\n 2. Delete from queue \n Enter your choice \t ";
	cin>>c2;
	switch(c2)
	{
		case 1:  cout<<"\n Enter the element to enter \t";
				 cin>>x;
		         q.enqueue(x);
		         q.show();
		         break;
		case 2:  r=q.dequeue();
		         cout<<"\n Deleted element is  "<<r;
		         q.show();
		         break;
	}
	cout<<"\n Do you wish to continue? \n Yes:y  No:n \t";
	cin>>w;
    }while(w=='y' ||w=='Y');
	return 0;
}
