#include<iostream>
#include<stdlib.h>
using namespace std;

template<class t>
class diamatrix
{
	t *A;
	int size;
	public :
		diamatrix()
		{
			size=10;
			A=new t[size];	
		}
		diamatrix(int n)
		{
			size=n;
			A=new t[size];
		}
		void store(t x,int,int);
		t retrieve(int i,int j);
};

template<class t>
void diamatrix<t>::store(t x,int i,int j)
{
	if(i<0 || j<0 || i>=size ||j>=size)
	  {
	    cout<<"Array index out of bounds";
        exit(1);
      }
    if(i==j)
    	A[i]=x;
}



template<class t>
t diamatrix<t>::retrieve(int i,int j)
{
	 if(i<0 || j<0 || i>=size ||j>=size)
	  {
	    cout<<"Array index out of bounds";
        exit(1);
      }
      t g;
	if(i==j)
	  {
		g=A[i];
		return g;
	  }
    else
    	return 0;
       
}

template<class t>
class lowmatrix
{
	t *A;
	int size;
	public:
		lowmatrix()
		{
			size=10;
			A=new t[size];
		}
		lowmatrix(int n)
		{
			size=n*(n+1)/2;
			A=new t[size];
		}
		void store(t x,int,int);
		t retrieve(int ,int);
};

template<class t>
void lowmatrix<t>::store(t x,int i,int j)
{
	if(i<0 || j<0 || i>=size ||j>=size)
	  {
	    cout<<"Array index out of bounds";
        exit(1);
      }
    if(i>=j)
      A[(i*(i+1)/2)+j]=x;
    
}

template<class t>
t lowmatrix<t>::retrieve(int i,int j)
{
	 if(i<0 || j<0 || i>=size ||j>=size)
	  {
	    cout<<"Array index out of bounds";
        exit(1);
      }
     t g;
	 if(i>=j)
	  {
		g=A[(i*(i+1)/2)+j];
		return g;
	  }
     else
    	return 0;
       
}

template<class t>
class upmatrix
{
	int size;
	t *A;
	public:
	    upmatrix()
		{
			size=10;
			A=new t[size];
		}
		upmatrix(int n)
		{
			size=n*(n+1)/2;
			A=new t[size];
		}
		void store(t x,int,int);
		t retrieve(int ,int);	
};

template<class t>
void upmatrix<t>::store(t x,int i,int j)
{
	t h;
	if(i<0 || j<0 || i>=size ||j>=size)
	  {
	    cout<<"Array index out of bounds";
        exit(1);
      }
    if(i<=j)
    {
      h=((i*size)+j)-(i*(i+1)/2);
      A[h]=x;
    }
}

template<class t>
t upmatrix<t>::retrieve(int i,int j)
{
	 if(i<0 || j<0 || i>=size ||j>=size)
	  {
	    cout<<"Array index out of bounds";
        exit(1);
      }
     t g,h;
	 if(i<=j)
	  {
	  	h=((i*size)+j)-(i*(i+1)/2);
		g=A[h];
		return g;
	  }
     else
    	return 0;
       
}



template<class t>
class symmatrix
{
	t *A;
	int size;
	public:
		symmatrix()
		{
			size=10;
			A=new t[size];
		}
		symmatrix(int n)
		{
			size=n*(n+1)/2;
			A=new t[size];
		}
		void store(t x,int,int);
		t retrieve(int ,int);
};

template<class t>
void symmatrix<t>::store(t x,int i,int j)
{
	if(i<0 || j<0 || i>=size ||j>=size)
	  {
	    cout<<"Array index out of bounds";
        exit(1);
      }
    if(i>=j)
      A[(i*(i+1)/2)+j]=x;
    
}

template<class t>
t symmatrix<t>::retrieve(int i,int j)
{
	 if(i<0 || j<0 || i>=size ||j>=size)
	  {
	    cout<<"Array index out of bounds";
        exit(1);
      }
     t g;
	 if(i>=j)
	  {
		g=A[(i*(i+1)/2)+j];
		return g;
	  }
     else
      {
      	g=A[(j*(j+1)/2)+i];
		return g;
	  }
       
}


int main()
{
	int size,ch;
	char m;
	do
	{
	  cout<<"\nMAIN MENU"<<"\n1.Diagonal Matrix"<<"\n2.Lower Triangular Matrix"<<"\n3.Upper Triangular Matrix"<<"\n4.Symmetric Matrix";
	  cout<<"\n \nEnter your choice \t";
	  cin>>ch;
	  switch(ch)
	  { 
	  	case 1:{
	   
		         cout<<"\nEnter size of square matrix \t";
	             cin>>size;
				 diamatrix <int>d(size);
	             int x;
	             cout<<"\nEnter the elements of matrix\n";
	             for(int i=0;i<size;i++)
	             {
	 	            for(int j=0;j<size;j++)
	 	             {
		                 cin>>x;
	                     d.store(x,i,j);
                     }
                 }
                 int g;
                 cout<<"\nElements in diagonal sparse matrix are \n \n";
	             for(int i=0;i<size;i++)
                 {
 	                 for(int j=0;j<size;j++)
 	                  {
 	                      g=d.retrieve(i,j);
 	                      cout<<g<<" ";
                      }
                     cout<<endl;
                 }
                 break;
                 
               }
               
               
        case 2:{

        	     cout<<"\nEnter size of square matrix \t";
	             cin>>size;
				 lowmatrix <int>d(size);
	             int x;
	             cout<<"\nEnter the elements of matrix\n";
	             for(int i=0;i<size;i++)
	             {
	 	            for(int j=0;j<size;j++)
	 	             {
		                 cin>>x;
	                     d.store(x,i,j);
                     }
                 }
                 int g;
                 cout<<"\nElements in lower trianglular sparse matrix are \n \n";
	             for(int i=0;i<size;i++)
                 {
 	                 for(int j=0;j<size;j++)
 	                  {
 	                      g=d.retrieve(i,j);
 	                      cout<<g<<" ";
                      }
                     cout<<endl;
                 }
                 break;
        	}
		         
		case 3:{
			      
			     cout<<"\nEnter size of square matrix \t";
	             cin>>size;
				 upmatrix <int>d(size);
	             int x;
	             cout<<"\nEnter the elements of matrix\n";
	             for(int i=0;i<size;i++)
	             {
	 	            for(int j=0;j<size;j++)
	 	             {
		                 cin>>x;
	                     d.store(x,i,j);
                     }
                 }
                 int g;
                 cout<<"\nElements in upper trianglular sparse matrix are \n \n";
	             for(int i=0;i<size;i++)
                 {
 	                 for(int j=0;j<size;j++)
 	                  {
 	                      g=d.retrieve(i,j);
 	                      cout<<g<<" ";
                      }
                     cout<<endl;
                 }
			     break;
		      }
		      
		case 4:{
			     cout<<"\nEnter size of square matrix \t";
	             cin>>size;
				 symmatrix <int>d(size);
	             int x;
	             cout<<"\nEnter the elements of matrix\n";
	             for(int i=0;i<size;i++)
	             {
	 	            for(int j=0;j<size;j++)
	 	             {
		                 cin>>x;
	                     d.store(x,i,j);
                     }
                 }
                 int g;
                 cout<<"\nElements in symmetric sparse matrix are \n \n";
	             for(int i=0;i<size;i++)
                 {
 	                 for(int j=0;j<size;j++)
 	                  {
 	                      g=d.retrieve(i,j);
 	                      cout<<g<<" ";
                      }
                     cout<<endl;
                 }
			     
			     
			     break;
		}
	  }
	  cout<<"\nDo you wish to continue (Yes-Y),(No-N):";
	  cin>>m;
    }while(m=='y'||m=='Y');
return 0;
}
