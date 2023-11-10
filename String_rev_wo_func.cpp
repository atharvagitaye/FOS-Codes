#include<iostream>
using namespace std;

int main()
{
    int num,i;

    cout<<"Enter how long string is ?"<<endl;
    cin>>num;

    char s[num];
    cout<<"Enter the string:"<<endl;
    cin>>s;

    for(i=num;i>=0;i--)
    {
        cout<<s[i];
    }

}
