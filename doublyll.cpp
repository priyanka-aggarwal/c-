#include<iostream>
#include<stdlib.h>
using namespace std;

class node
{
	int info;
	node *next;
	node *prev;
	
	public:
	    node()
	    {
	    	info=0;
	    	next=NULL;
	    	prev=NULL;
	    }
	    node(int x=0,node *n=NULL, node *p=NULL)
	    {
	    	info=x;
	    	next=n;
	    	prev=p;
	    }
		friend class linklist;
	
};

class linklist
{
	 node *first, *last;
	public:
		linklist()
		{
			first=NULL;
			last=NULL;
		}
		void insert_end(int x);
		void insert_beg(int x);
		void insert_pos(int x,int pos);
		void show();
		int del_beg();
		int del_end();
		int del_pos(int pos);
		int length();
};

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
         first=last=n;
    else
    {
    n->next=first;
    first->prev=n;
    first=n;
    }
}

void linklist::insert_end(int x)
{
     node *n=new node(x);
     if(first==NULL)
        first=last=n;
     else
     {
	 last->next=n;
     n->prev=last;
     last=n;
     }
}

void linklist::insert_pos(int x,int pos)
{
	node *temp=first;
	node *n=new node(x);
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
      for(int i=0;i<pos;i++)
          temp=temp->next;
      n->next=temp->next;
      n->prev=temp;
      temp->next->prev=n;
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
	first->prev=NULL;
	delete temp;
	return x;
}

int linklist::del_pos(int pos)
{
	node *temp=first;
	int x;
	node *t;
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
    	last=NULL;
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
       for(int i=1;i<pos;i++)
          temp=temp->next;
       t=temp->next;
       temp->next=t->next;
       t->next->prev=temp;
       x=t->info;
       delete t;
    }
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
	 else if(temp->next==NULL)
    {
       int	x=temp->info;
    	delete temp;
    	first=NULL;
    	last=NULL;
    	return x;
	}
	node *t=last;
	int x=t->info;
	last=last->prev;
	last->next=NULL;
	delete t;
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


