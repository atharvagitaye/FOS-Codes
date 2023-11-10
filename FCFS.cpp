#include<iostream>
using namespace std;

class FCFS
{
    public:
        int atime,btime,wt,rt,tt,pnum,i;
        void input_info(int count);
};

void FCFS::input_info(int count)
{
    pnum=count+1;

    cout<<"\nEnter the arrival time of process "<<pnum<<" :"<<endl;
    cin>>atime;

    cout<<"Enter burst time of the process "<<pnum<<" :"<<endl;
    cin>>btime;
}

void calc(FCFS *f,int np);
void avg(FCFS *f,int np);
void display(FCFS *f,int np);

void calc(FCFS *f,int np)
{
    int i;
    f[0].rt=0;

    for(i=1;i<np;i++)
    {
        f[i].rt=f[i-1].btime+f[i-1].rt;

        if(f[i].rt<=f[i].atime)
        {
            f[i].rt=f[i].atime;
        }
    }

    f[0].wt=0;

    for(i=1;i<np;i++)
    {
        f[i].wt=f[i].rt-f[i].atime;
    }

    for(i=0;i<np;i++)
    {
        f[i].tt=f[i].wt+f[i].btime;
    }
}

void avg(FCFS *f,int np)
{
    float wtavg=0,ttavg=0;
    int i;

    for(i=0;i<np;i++)
    {
        wtavg=f[i].wt+wtavg;
        ttavg=f[i].tt+ttavg;
    }

    wtavg=wtavg/(np);
    ttavg=ttavg/(np);

    cout<<endl;
    cout<<"\nAverage waiting time= "<<wtavg<<endl;
    cout<<"Average turn around time= "<<ttavg<<endl;
}

void display(FCFS *f,int np)
{
    cout<<endl;
    cout<<"Processes"<<"\tArrival time"<<"\tBurst time"<<"\tWaiting time"<<"\tTurn around time\n";
    for(int i=0;i<np;i++)
    {
        cout<<"\nPID"<<f[i].pnum<<"\t\t"<<f[i].atime<<"\t\t"<<f[i].btime<<"\t\t"<<f[i].wt<<"\t\t"<<f[i].tt;
    }
}

int main()
{
    int np,i,j;

    cout<<"Enter number of processes:"<<endl;
    cin>>np;

    FCFS f[np],temp;

    for(i=0;i<np;i++)
    {
        f[i].input_info(i);
    }

    for(i=0;i<np;i++)
    {
        for(j=i+1;j<np;j++)
        {
            if(f[i].atime>f[j].atime)
            {
                temp=f[i];
                f[i]=f[j];
                f[j]=temp;
            }
        }
    }

    calc(f,np);
    display(f,np);
    avg(f,np);
}
