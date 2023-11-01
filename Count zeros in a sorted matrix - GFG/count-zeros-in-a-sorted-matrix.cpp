//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
public:
	int countZeros(vector<vector<int>>A)
	{
		//code here
		int n=A.size(), cnt=0;
		for(int i=0;i<n;i++){
		    int low=0, high=n-1,res=0;
		    while(low<=high){
		        int mid=low+(high-low)/2;
		        if(A[i][mid]==0){
		            res=mid+1;
		            low=mid+1;
		        }
		        else{
		            high=mid-1;
		        }
		    }
		    cnt+=res;
		}
		return cnt;
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>>A(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                cin>>A[i][j];
            }
        }
        Solution ob;
        cout<<ob.countZeros(A)<<'\n';
    }
    return 0;
}

// } Driver Code Ends