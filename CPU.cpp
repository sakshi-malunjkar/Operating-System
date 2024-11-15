#include<iostream>
using namespace std;
class cpu
{
    public : 
            int p;
            int temp;
            int tem;
            int choice;
            int P[30];
            int WT[30];
            int BT[30];
            int TAT[30];
            int CT[30];
            int Priority[30];
            int Time_quantum;
            int completed=0;
            int remain_time[30];
            int current_time =0;
            int comp_time[30] ;
            bool C[30] = {false};
            int i=0;


            void fcfs();
            void sjf();
            void pri();
            void RR();
            void menu();

};


void cpu::fcfs()
{
    cout<<"Enter the no. of processes : ";
    cin>>p;
    cout<<"Enter the Process ID : ";
    for(int i=0;i<p;i++)
    {
        cout<<"P";
        cin>>P[i];
    }
    cout<<endl;
    cout<<"Enter the Burst Time :";
    for(int i =0;i<p;i++)
    {
    cin>>BT[i];
    }
    cout<<endl;
    WT[0]=0;
    for(int i=1;i<=p;i++)
    {
        WT[i] = WT[i-1] + BT[i-1];
    }
    for(int i=0;i<p;i++)
    {
        TAT[i] = WT[i] + BT[i];
        CT[i] = TAT[i];
    }
     cout<<"Proccess"<<"\t\t"<<"Burst Time"<<"\t\t"<<"CT"<<"\t\t"<<"WT"<<"\t\t"<<"TAT"<<endl;
    for(int i =0;i<p;i++)
    {
        cout<<"P"<<i+1<<"\t\t"<<BT[i]<<"\t\t"<<CT[i]<<"\t\t"<<WT[i]<<"\t\t"<<TAT[i]<<endl;
    }

}

void cpu::sjf()
{
    cout<<"Enter the no. of processes : ";
    cin>>p;
    cout<<"Enter the Process ID : ";
    for(int i=0;i<p;i++)
    {
        cout<<"P";
        cin>>P[i];
    }
    cout<<endl;
    cout<<"Enter the Burst Time :";
    for(int i =0;i<p;i++)
    {
    cin>>BT[i];
    }
    cout<<endl;

    for(int i=0;i<p-1;i++)
    {
        for(int j=0;j<p-i-1;j++)
        {
            if(BT[j]>BT[j+1])
            {
                temp = BT[j];
                BT[j] = BT[j+1];
                BT[j+1] = temp;
            }
        }
    }

     WT[0]=0;
    for(int i=1;i<=p;i++)
    {
        WT[i] = WT[i-1] + BT[i-1];
    }
    for(int i=0;i<p;i++)
    {
        TAT[i] = WT[i] + BT[i];
        CT[i] = TAT[i];
    }
 cout<<"Proccess"<<"\t\t"<<"Burst Time"<<"\t\t"<<"CT"<<"\t\t"<<"WT"<<"\t\t"<<"TAT"<<endl;
    for(int i =0;i<p;i++)
    {
        cout<<"P"<<i+1<<"\t\t"<<BT[i]<<"\t\t"<<CT[i]<<"\t\t"<<WT[i]<<"\t\t"<<TAT[i]<<endl;
    }
}

void cpu:: pri()
{
    
    cout<<"Enter the no. of processes : ";
    cin>>p;
    cout<<"Enter the Process ID : ";
    for(int i=0;i<p;i++)
    {
        cout<<"P";
        cin>>P[i];
    }
    cout<<endl;
    cout<<"Enter the Burst Time :";
    for(int i =0;i<p;i++)
    {
    cin>>BT[i];
    }
    cout<<endl;

    cout<<"Enter the Priority : ";
    for(int i=0;i<p;i++)
    {
        cin>>Priority[i];
    }
    cout<<endl;

    for(int i=0;i<p-1;i++)
    {
        for(int j=0;j<p-i-1;j++)
        {
            if(Priority[j]>Priority[j+1])
            {
                temp = Priority[j];
                Priority[j] = Priority[j+1];
                Priority[j+1] = temp;

                temp = BT[j];
                BT[j] = BT[j+1];
                BT[j+1] = temp;
            }
        }
    }

     WT[0]=0;
    for(int i=1;i<=p;i++)
    {
        WT[i] = WT[i-1] + BT[i-1];
    }
    for(int i=0;i<p;i++)
    {
        TAT[i] = WT[i] + BT[i];
        CT[i] = TAT[i];
    }
 
 cout<<"Proccess"<<"\t\t"<<"Burst Time"<<"\t\t"<<"CT"<<"\t\t"<<"WT"<<"\t\t"<<"TAT"<<endl;
    for(int i =0;i<p;i++)
    {
        cout<<"P"<<i+1<<"\t\t"<<BT[i]<<"\t\t"<<CT[i]<<"\t\t"<<WT[i]<<"\t\t"<<TAT[i]<<endl;
    }
}
void cpu::RR()
{
    cout<<"Enter the no. of processes : ";
    cin>>p;
    cout<<"Enter the Process ID : ";
    for(int i=0;i<p;i++)
    {
        cout<<"P";
        cin>>P[i];
    }
    cout<<endl;
    cout<<"Enter the Burst Time :";
    for(int i =0;i<p;i++)
    {
    cin>>BT[i];
    remain_time[i] = BT[i];
    }
    cout<<endl;

    cout<<"Enter the Time Quantum : ";
    cin>>Time_quantum;
    cout<<endl;

    while(completed<p)
    {
        for(int i=0;i<p;i++)
        {
            if(!C[i])
            {
                if(remain_time[i]<=Time_quantum)
                {
                    current_time += remain_time[i];
                    remain_time[i] = 0;
                    comp_time[i] = current_time;
                    C[i] = true;
                    completed++;

                }

                else
                   current_time+= Time_quantum;
                   remain_time[i]-= Time_quantum;
            }
        }
    }
    
    for(int i=0;i<p;i++)
    {
        TAT[i] = comp_time[i];
        WT[i] = TAT[i] - BT[i];
    }

    cout<<"Proccess"<<"\t\t"<<"Burst Time"<<"\t\t"<<"CT"<<"\t\t"<<"WT"<<"\t\t"<<"TAT"<<endl;
    for(int i =0;i<p;i++)
    {
        cout<<"P"<<i+1<<"\t\t"<<BT[i]<<"\t\t"<<comp_time[i]<<"\t\t"<<WT[i]<<"\t\t"<<TAT[i]<<endl;
    }
}



int main()
{
    cpu a;
    /*a.read();
    a.fcfs();
    a.sjf();
    a.dis();*/
    a.menu();
return 0;

}

void cpu::menu()
{
    int choice;

    do
    {
            cout<<"1.FCFS\n";
            cout<<"2.SJF\n";
            cout<<"3.PRIORITY\n";
            cout<<"4.ROUND ROBIN\n";
            cout<<"5.EXIT\n";

            cout<<"Enter the choice : ";
            cin>>choice;

            switch(choice)
            {
                
                case 1 : 
                        fcfs();
                        break;
                case 2 :
                        sjf();
                        break;
                case 3 : 
                        pri();
                        break;
                case 4 : 
                        RR();
                        break;
                case 5 : 
                        cout<<"Existing the menu!\n";
                        break;
                default :
                        cout<<"Invalid Choice !";
                        break;
            }

        }while(choice!=5);
    }

