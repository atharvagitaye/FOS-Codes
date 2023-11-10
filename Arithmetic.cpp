#include<iostream>
using namespace std;

int main()
{
    int s;
    float a,b,c;

    cout<<"Enter 1st number:"<<endl;
    cin>>a;
    cout<<"Enter 2nd number:"<<endl;
    cin>>b;

    cout<<endl<<"-----Menu-----"<<endl;
    cout<<"1. Addition"<<endl;
    cout<<"2. Subtraction"<<endl;
    cout<<"3. Multiplication"<<endl;
    cout<<"4. Division"<<endl<<endl;

    cout<<"Enter the option:"<<endl;
    cin>>s;

    switch(s)
    {
        case 1: c=a+b;
                cout<<endl<<"Addition = "<<c<<endl;
                break;

        case 2: c=a-b;
                cout<<endl<<"Subtraction = "<<c<<endl;
                break;

        case 3: c=a*b;
                cout<<endl<<"Multiplication = "<<c<<endl;
                break;

        case 4: c=a/b;
                cout<<endl<<"Division = "<<c<<endl;
                break;

        default: cout<<endl<<"Wrong input"<<endl;
                 break;

    }
}
