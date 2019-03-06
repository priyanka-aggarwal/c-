#include<iostream>
using namespace std;
template <class T>
class array
{
      T *a;
      int size;
      public:
         array(int s)
         {
                   size=s;
                   a=new T[size];
         }
         array(array  &h)
         {   size=h.size;
             a=new T[size];
            cout<<"elements \n";
            for(int i=0;i<size;i++)
            {
                cout<<h.a[i]<<endl;     
            }         
         }
         ~ array()
         {
             cout<<"deleting size";
         }
      void enter();
};
template <class T>
void array<T>::enter()
{
     cout<<"enter the elements of array";
     for(int i=0;i<size;i++)
     {
             cin>>a[i];
     }
}
             
            int main()
            {
                int s;
                
             cout<<"enter size of array";
             cin>>s;   
                  array<char> a(s);
                  a.enter();
                  array<char> r(a);
                      
             system("pause");
             return 0;
             }       
