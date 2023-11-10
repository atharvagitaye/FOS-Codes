#include<iostream>
using namespace std;

int main()
{
    int num,i,ans=0;

    cout<<"Enter the number:"<<endl;
    cin>>num;

    if(num%2==0)
    {
        cout<<endl<<"Number is even"<<endl;
    }

    if(num%2==1)
    {
        cout<<endl<<"Number is odd"<<endl;
    }

    for(i=2;i<=num/2;i++)
    {

        if (num%i==0)
        {
            ans=1;
            break;
        }
    }

    if(ans==0)
    {
        cout<<endl<<num<<" is prime number"<<endl;
    }
    else
    {
        cout<<endl<<num<<" is not prime number"<<endl;
    }
}
