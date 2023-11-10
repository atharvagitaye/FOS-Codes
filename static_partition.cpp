#include<iostream>
using namespace std;

class Static_Partition
{
    public:
        int psize,acc_pname=0;
        int flag=0,frag=0;
};

int main()
{
    int msize;
    int pnum,prcnum,i,j,x=0;

    cout<<"Enter total memory size:"<<endl;
    cin>>msize;
    cout<<"\nEnter the number of partitions:"<<endl;
    cin>>pnum;

    Static_Partition s[pnum];

    for(i=0;i<pnum;i++)
    {
        x=0;
        while(x==0)
        {
            cout<<"\nEnter the size of partition "<<i+1<<" :"<<endl;
            cin>>s[i].psize;

            if(s[i].psize<=msize)
            {
                msize=msize-s[i].psize;
                x=1;
            }
            else
            {
                cout<<"\nPartition size should be less than memory size"<<endl;
            }
        }
    }

    cout<<"\nEnter the number of processes:"<<endl;
    cin>>prcnum;

    int prcsize[prcnum];

    for(i=0;i<prcnum;i++)
    {
        cout<<"\nEnter the size of process "<<i+1<<" :"<<endl;
        cin>>prcsize[i];

        for(j=0;j<pnum;j++)
        {
            if(s[j].flag==0)
            {
                if(prcsize[i]<=s[j].psize)
                {
                    s[j].flag=1;
                    s[j].acc_pname=i+1;

                    if(prcsize[i]<s[j].psize)
                    {
                        s[j].frag=1;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }

    cout<<"\n\t\t\t***** Partition Description Table *****"<<endl;
    cout<<"\nPartition No.\tPartition Size\tStatus\t\tAllocated process\tInternal Fragmentation"<<endl;
    for(i=0;i<pnum;i++)
    {
        cout<<"\n"<<i+1<<"\t\t"<<s[i].psize;
        if(s[i].flag==1)
        {
            cout<<"\t\tAllocated";
        }
        else
        {
            cout<<"\t\tFree\t";
        }

        if(s[i].acc_pname!=0)
        {
            cout<<"\t"<<s[i].acc_pname;

            if(s[i].frag==1)
            {
                cout<<"\t\t\tYes";
            }
            else
            {
                cout<<"\t\t\tNo";
            }
        }
        else
        {
            cout<<"\t-\t\t\t-";
        }
    }
    cout<<endl;
}
