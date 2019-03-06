//recursion
#include<iostream>
using namespace std;
int power(int b, int r)
{
    if(b==1)
            return 1;
    else if(b==0)
                 return 0;
    else if(r==0)
                 return 1;
    int ans=b*power(b,r-1);
    return ans;
}
int main()
{
    int n,r,ans;
    cout<<"Enter the value of n and r to find n^r\n";
    cin>>n>>r;
    ans=power(n,r);
    cout<<n<<"^"<<r<<" ="<<ans;
    cout<<"\n";
    system("pause");
    return 0;
}
