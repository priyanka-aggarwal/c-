#include<iostream>
#include<stdlib.h>
using namespace std;

class node
{
	int info;
	node *next;
	
	public:
	    node()
	    {
	    	info=0;
	    	next=NULL;
	    }
	    node(int x=0,node *n=NULL)
	    {
	    	info=x;
	    	next=n;
	    }
		friend class linklist;
	
};

class linklist
{
	 node *first;
	public:
		linklist()
		{
			first=NULL;
		}
		void insert_end(int x);
		void insert_beg(int x);
		void insert_pos(int x,int pos);
		int length();
		void show();
		int del_beg();
		int del_end();
		int del_pos(int pos);
};

void linklist::insert_end(int x)
{
	node *temp=first;
	if(first==NULL)
	  first=temp;
	while(temp->next!=NULL)
	  temp=temp->next;
	node *n=new node(x);
    temp->next=n;

}

int linklist::length()
{
	int l;
	node *temp=first;
	while(temp!=NULL)
	{
		l=l+1;
		temp=temp->next;
	}
	return l;
}

void linklist::insert_beg(int x)
{
	node *n=new node(x);
	if(first==NULL)
	  first=n;
	else
	{
		n->next=first;
		first=n;
	}
}

void linklist::insert_pos(int x,int pos)
{
	node *temp=first;
	int l=length();
	 int c=1;
	 if(pos==1)
	   {
	     insert_beg(x);
	   }
	 else if(pos>l)
	 {
	 	insert_end(x);
	 }
	 else
	 {
	 	while(c<pos-1)
	 	{
	 		c++;
			temp=temp->next;
		 }
		 node *n=new node(x);
		 	n->next=temp->next;
		 	temp->next=n;
		 
	 }
}

void linklist::show()
{
	node *temp=first;
	cout<<"\n THE LIST IS :";
	while(temp!=NULL)
	  {
	     cout<<(temp->info)<<"->";
	     temp=temp->next;
	 }
	    cout<<"null";
}

int linklist::del_beg()
{
	if(first==NULL)
	 {
	 	cout<<"\nList is empty";
	 	return -1;
	 }
	node *temp=first;
	first=first->next;
	int x=temp->info;
	delete temp;
	return x;
}

int linklist::del_end()
{
	node *temp=first;
	if(first==NULL)
	 {
	 	cout<<"\nList is empty";
	 	return -1;
	 }
	 else if(first->next==NULL)
    {
       int	x=temp->info;
    	delete temp;
    	first=NULL;
    	return x;
	}

	while(temp->next->next!=NULL)
	  temp=temp->next;
	node *t=temp->next;
	int x=t->info;
	temp->next=NULL;
	delete t;
	return x;
}

int linklist::del_pos(int pos)
{
	node *temp=first;
	int x;
	int len=length();
	if(first==NULL)
	{
		cout<<"Empty";
		return -1;
	}
    else if(temp->next==NULL)
    {
    	x=temp->info;
    	delete temp;
    	first=NULL;
	}
	else if(pos==1)
	{
	  x=del_beg();	
	}
	else if(pos==len)
	{
	  x=del_end();
	}
	else
	{
	  int l=1;
	  node *t;
      while(l<pos-1)
       {
    	temp=temp->next;
    	l++;
	   }
	 t=temp->next;
  	 temp->next=temp->next->next;  
     x=t->info;
	 delete t;
    } 
	return x;	
}

int main()
{
	linklist a;
	int ch,x;
	char y;
	int pos;
	do
	{
	  cout<<"\n\nMAIN MENU \n1.Insert the elment in the beginning \n2.Insert the element in end"; 
	  cout<<"\n3.Insert the element in given position \n4.Delete from begining \n";
	  cout<<"5.Delete from end \n6.Delete from given position \n7.Show";
	  cout<<"\n \nEnter your choice  ";
	  cin>>ch;
		switch(ch)
		{
			case 1: 
			        cout<<"\n \nEnter the element to be inserted\t";
			        cin>>x;
			        a.insert_beg(x);
			        break;
			
			case 2:
				    cout<<"\n \nEnter the element to be inserted\t";
				    cin>>x;
				    a.insert_end(x);
				    break;
			
			case 3:
				    cout<<"\n \nEnter the element to be inserted\t";
					cin>>x;
					cout<<"\nEnter the position at which element to be inserted\t";
					cin>>pos;
					a.insert_pos(x,pos);
					break;
					
		   case 7:
		   	        cout<<"\n \nLinked list is\n";
		   	        a.show();
		   	        break;
		   	        
		   case 4: 
		           x=a.del_beg();
		           if(x==-1);
		           else
		             cout<<"\nDeleted element is"<<x;
		            break;
		            
		   case 5:
		  	      x=a.del_end();
		  	      if(x==-1);
		          else
		            cout<<"\nDeleted element is"<<x;
		          break;
		  	      
		  case 6: 
		          cout<<"\nEnter the position";
		          cin>>pos;
		  	      x=a.del_pos(pos);
		  	      if(x==-1);
		          else
		            cout<<"\nDeleted element is"<<x;
		          break;     
		  	      
		}
	
	  cout<<"\n \nDo you wish to continue? (Yes-Y ,No-N)  ";
	  cin>>y;
    }while(y=='Y' || y=='y');
	return 0;
}

