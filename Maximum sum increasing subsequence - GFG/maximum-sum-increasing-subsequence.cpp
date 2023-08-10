//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int nums[], int n)  
	{  
	    // Your code goes here
	   // int n=nums.size();
        vector<int> c(n+1, 0);
        vector<int> p(n+1, 0);

        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int take=INT_MIN, notTake=INT_MIN;
                if(prev==-1 || nums[prev]<nums[curr]){
                    take = nums[curr] + c[curr+1];
                }
                notTake=c[prev+1];
                p[prev+1]=max(take, notTake);
            }
            c=p;
        }
        return p[0];
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends