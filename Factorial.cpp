 #include<iostream>
 using namespace std;

 int main()
 {
     int i=0,num,fact=1;

     cout<<"Enter number to find factorial:"<<endl;
     cin>>num;

     for(i=1;i<=num;i++)
     {
         fact=fact*i;
     }

     cout<<endl<<"Factorial= "<<fact<<endl;
 }
