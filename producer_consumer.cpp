#include<iostream>
using namespace std;

int mutex=1,full=0,empty=3,x=0;

int main()
{
    int n;

    void producer();
    void consumer();
    int wait(int);
    int signal(int);

    cout<<"1.Producer"<<endl;
    cout<<"2.Consumer"<<endl;
    cout<<"3.Exit"<<endl;

    while(1)
    {
        cout<<"\nEnter your choice:"<<endl;
        cin>>n;

        switch(n)
        {
            case 1: if((mutex==1)&&(empty!=0))
                    {
                        producer();
                    }
                    else
                    {
                        cout<<"Buffer is full !!"<<endl;
                    }

                    break;

            case 2: if((mutex==1)&&(full!=0))
                    {
                        consumer();
                    }
                    else
                    {
                        cout<<"Buffer is empty !!"<<endl;
                    }

                    break;

            case 3: exit(0);
                    break;

            default:cout<<"You have entered wrong option"<<endl;
                    break;
        }
    }
}

int wait(int s)
{
    return(--s);
}

int signal(int s)
{
    return (++s);
}

void producer()
{
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    cout<<"\nProducer produces the item"<<x<<endl;
    mutex=signal(mutex);
}

void consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    cout<<"Consumer consumes item"<<x<<endl;
    x--;
    mutex=signal(mutex);
}
