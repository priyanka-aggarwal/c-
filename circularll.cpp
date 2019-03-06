#include<iostream>
#include<stdlib.h>
using namespace std;

template <class t1>
class node
{
	t1 info;
	node *next;
	
	public:
	    node()
	    {
	    	info=0;
	    	next=NULL;
	    }
	    node(t1 x=0,node *n=NULL)
	    {
	    	info=x;
	    	next=n;
	    }
		template <class t2>friend class linklist;
	
};

template <class t1>
class linklist
{
	 node <t1>*last;
	public:
		linklist()
		{
			last=NULL;
		}
		void insert_end(t1 x);
		void insert_beg(t1 x);
		void insert_pos(t1 x,int pos);
		int length();
		void show();
		t1 del_beg();
		t1 del_end();
		t1 del_pos(int pos);
		int search(t1 x);
		void reverse();
};

template <class t1>
void linklist<t1>::insert_beg(t1 x)
{
	node<t1> *n=new node<t1>(x);
	if(last==NULL)
	  {
	    last=n;
	    last->next=n;
      }
	else
	{
		n->next=last->next;
		last->next=n;
	}
}

template <class t1>
void linklist<t1>::insert_end(t1 x)
{
	node <t1>*n=new node<t1>(x);
	if(last==NULL)
	{
		last=n;
		last->next=n;
	}
	else
	{
		n->next=last->next;
		last->next=n;
		last=n;
	}
}

template <class t1>
int linklist<t1>::length()
{
	int l;
	node <t1>*temp=last->next;
	while(temp!=NULL)
	{
		l=l+1;
		temp=temp->next;
	}
	return l;
}

template <class t1>
void linklist<t1>::insert_pos(t1 x,int pos)
{
	node <t1>*temp=last->next;
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
		 node <t1>*n=new node<t1>(x);
		 n->next=temp->next;
		 temp->next=n;
	 }
}

template <class t1>
void linklist<t1>::show()
{
	node <t1>*temp=last->next;
	cout<<"\n THE LIST IS :";
	if(last==NULL)
	{
		cout<<"empty";
		return;
	}
	  	
	do
	{
	     cout<<(temp->info)<<"->";
	     temp=temp->next;
	}while(temp!=last->next);
	cout<<"null";
}

template <class t1>
t1 linklist<t1>::del_beg()
{
	if(last==NULL)
	 {
	 	cout<<"\nList is empty";
	 	return -1;
	 }
	node <t1>*temp=last->next;
	last->next=temp->next;
	int x=temp->info;
	delete temp;
	return x;
}

template <class t1>
t1 linklist<t1>::del_end()
{
	node <t1>*temp=last->next;
	if(last==NULL)
	 {
	 	cout<<"\nList is empty";
	 	return -1;
	 }

	while(temp->next->next!=NULL)
	temp=temp->next;
	int x=last->info;
	temp->next=NULL;
	delete last;
	last=temp;
	return x;
}

template <class t1>
t1 linklist<t1>::del_pos(int pos)
{
	node <t1>*temp=last->next;
	int x;
	int len=length();
	if(last==NULL)
	{
		cout<<"Empty";
		return -1;
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
	  node <t1>*t;
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

template<class t1>
int linklist<t1>::search(t1 x)
{
	node <t1>*temp=last;
	int c=1,flag=-1;
	if(last==NULL)
	{
		cout<<"List is empty";
		return flag;
	}
	do
	{
		c++;
		if(temp->info==x)
		  {
		     flag=1;
			 return c;
	      }
	}while(temp!=last);
	return flag;
}

template<class t1>
void linklist<t1>::reverse()
{
	node<t1>*temp=last->next, *t=last->next, *prev=last;
	if((prev->next==NULL) || (temp->next==NULL))
	  return;
	do
	{
		temp=temp->next;
		t->next=prev;
		prev=t;
		t=temp;
	}while(temp!=last);
	last=last->next;
	temp->next=prev;

}

int main()
{
	linklist <int>a;
	int ch,x;
	char y;
	int pos;
	do
	{
	  cout<<"\n\nMAIN MENU \n1.Insert the elment in the beginning \n2.Insert the element in end"; 
	  cout<<"\n3.Insert the element in given position \n4.Delete from begining \n";
	  cout<<"5.Delete from end \n6.Delete from given position \n7.Show \n8.Search an element";
	  cout<<"\n9.Reverse the list\n \nEnter your choice  ";
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
		          
		  case 8:
		          cout<<"Enter the number to search";
		  	      cin>>x;
		  	      pos=a.search(x);
		  	      if(pos==-1)
		  	        cout<<"Element not found";
		  	      else
		  	        cout<<"Element found at position"<<pos;
		  	      break; 
		  	      
		  case 9:
		  	      a.reverse();
		  	      cout<<"List is reversed";
		  	      break;
		  	      
		}
	
	  cout<<"\n \nDo you wish to continue? (Yes-Y ,No-N)  ";
	  cin>>y;
    }while(y=='Y' || y=='y');
	return 0;
}
