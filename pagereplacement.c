#include<bits/stdc++.h> 
using namespace std; 


int pageFaults(int pages[], int n, int capacity) 
{ 
	
	unordered_set<int> s; 


	queue<int> indexes; 


	int page_faults = 0; 
	for (int i=0; i<n; i++) 
	{ 

		if (s.size() < capacity) 
		{ 
			
             
			if (s.find(pages[i])==s.end()) 
			{ 

				s.insert(pages[i]); 


				page_faults++; 


                
				indexes.push(pages[i]); 
			} 
		} 

		
		else
		{ 
			 
			if (s.find(pages[i]) == s.end()) 
			{ 
				
                
				int val = indexes.front(); 
				
				indexes.pop(); 

				s.erase(val); 

			
				s.insert(pages[i]); 

			
				indexes.push(pages[i]); 

				
				page_faults++; 
			} 
		} 
	} 

	return page_faults; 
} 

// Driver code 
int main() 
{ 
	
	int n1; 
	cout<<"Enter  no. of the pages:"<<endl;
	cin>>n1;
	int pages[n1];
	int capacity ; 
	cout<<" Enter the no. of frame:"<<endl;
	cin>>capacity;
	cout<<"Enter the page no.:"<<endl;
	for(int i=0;i<n1;i++)
	{
	 cin>>pages[i];
	}
	int n = sizeof(pages)/sizeof(pages[0]); 
	
	cout << "Page fault :" << pageFaults(pages, n, capacity)<<endl; 
	return 0; 
}

