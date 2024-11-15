#include<iostream>
#include<cstdlib>
using namespace std;

int mutex = 1;
int full = 0;
int empty = 0;
int x =0;

void producer()
{
    --mutex ;
     ++full;
     --empty;
     x++;
     cout<<"Producer produces item " << x << endl;
     ++mutex;
}

void consumer()
{
    --mutex;
    --full;
    ++empty;
     
    cout<<"Consumer consumes item "<< x << endl;
     x--;
    ++mutex;
}

int main()
{
    int n;
 cout<<"Enter the buffer size :\n";
 cin>>empty;

 if(empty<=0)
 {
    cout<<"Invalid choice !";
    return 1;
 }
    cout<<"1.Producer\n"
        <<"2.Consumer\n"
        <<"3.Exit\n";

    

    while(true)
    {
        cout<<"Enter the Choice : ";
    cin>>n;
        switch(n)
        {
            case 1 :
                     if(mutex == 1 && empty != 0 )
                     {
                        producer();
                     }
                     else
                     {
                        cout<<"Buffer is full!\n";

                     }
                     break;

            case 2 : 
                    if(mutex == 1 && full != 0)
                    {
                        consumer();
                    }
                    else
                    {
                        cout<<"Buffer is empty!\n";
                    }
                    break;

            case 3 : exit(0);
                    cout<<"Existing the menu!\n";
                    break;
            default :
                        cout<<"Invalid Choice !\n";
            
        }
    }
    return 0;


}