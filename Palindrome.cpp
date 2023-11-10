#include <iostream>
using namespace std;
int main()
{
    int n,r,sum=0,temp;

    cout<<"Enter the Number:";
    cin>>n;

    temp=n;

    while(n>0)
    {
        r=n%10;
        cout<<"r="<<r<<endl;
        sum=(sum*10)+r;
        cout<<"sum="<<sum<<endl;
        n=n/10;
        cout<<"n="<<n<<endl;
    }

    if(temp==sum)
    cout<<endl<<"Number is Palindrome"<<endl;
    else
    cout<<endl<<"Number is not Palindrome"<<endl;
    return 0;
}
