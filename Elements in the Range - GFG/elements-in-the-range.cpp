//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	bool check_elements(int arr[], int n, int A, int B)
	{
		// Your code goes here
		
		for(int i=0;i<n;i++){
		    if(abs(arr[i])>=A && abs(arr[i])<=B){
		        int idx=abs(arr[i])-A;
		        if(idx<n && arr[idx]>0){
		            arr[idx]*=-1;
		        }
		    }
		}
		int cnt=0;
		
		for(int i=0;i<=(B-A) && i<n;i++){
		    if(arr[i]>0){
		        return false;
		    }
		    else{
		        cnt++;
		    }
		}
		return cnt==(B-A+1);
	}


		 

};
	

//{ Driver Code Starts.


int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,A,B;
		cin>>n>>A>>B;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];

        

        Solution ob;
        if (ob.check_elements(a, n, A, B))
			cout << "Yes";
		else
			cout << "No";
	    
        
	    cout << "\n";
	     
    }
    return 0;
}







// } Driver Code Ends