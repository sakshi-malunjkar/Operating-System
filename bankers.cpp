#include<iostream>
using namespace std;

int main() 
{
    int n, p;
    cout << "Enter the total number of resource instances: ";
    cin >> n;
    int instance[n];  

    for (int i = 0; i < n; i++) 
    {
        cout << "Enter the total instances of resource " << char(65 + i) << ": ";
        cin >> instance[i];
    }

    cout << endl;

    cout << "Enter the total number of processes: ";
    cin >> p;
    int process[p],addition[n],safe[p],available[n];
    int allocate[p][n], max_need[p][n], remaining_need[p][n];
    
    for (int i = 0; i < p; i++) 
    {
        cout << "Process :-";
        cin>> process[i];
        
        cout << "Allocation of resources (one by one for each resource):\n";
        for (int j = 0; j < n; j++)
         {
            cin >> allocate[i][j];
         }
        

        cout << "Maximum need of resources (one by one for each resource):\n";  
        for (int j = 0; j < n; j++) 
        {
            cin >> max_need[i][j];
        }
    }

    for(int i=0 ;i<n; i++)
    {
        int sum=0;
        for(int j=0 ;j<p; j++)
        {
            sum= sum +allocate[j][i];
        }  
        addition[i]=sum; 
    } 
    cout<<endl;

    for(int i=0 ;i<n; i++)
    {
        available[i]=instance[i]-addition[i];
    }

   
    for (int i=0; i<p; i++)
    {
        for(int j=0 ;j<n; j++)
        {
            remaining_need[i][j]=max_need[i][j]-allocate[i][j];     
        }
    }
       
    bool finished[p] = {false};
    int index = 0;  
 
    while (index < p) 
    {
        bool found = false;  

        for (int i = 0; i < p; i++) 
        {
            
            if (!finished[i]) 
            {
                int count = 0;

                for (int j = 0; j < n; j++) 
                {
                    if (available[j] >= remaining_need[i][j])
                    {
                        count++;
                    }
                }

                
                if (count == n) 
                {
                  
                  
                    safe[index] = i + 1;
                    index++;

                
                    for (int k = 0; k < n; k++) 
                    {
                        available[k] += allocate[i][k];
                    }

                 
                    finished[i] = true;
                    found = true;
                 }
            }
        }


        if (!found) 
        {
            cout << "The system is not in a safe state." << endl;
            return 0;
        }
    }

 
    cout << "The safe sequence of processes is as follows:\n";
    for (int i = 0; i < p; i++) {
        cout << "P[" << safe[i] << "]" << endl;
    }

}


3
10
5
7

0 1 0 
2 0 0
3 0 2
2 1 1
0 0 2


7 5 3 
3 2 2 
9 0 2 
4 2 2 
5 3 3 