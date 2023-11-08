//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here   
        int i=0, j=0, s=0, len=1e6;
        
        while(j<n){
            s+=arr[j];
            while(i<=j && s>x){
                len=min(len, j-i+1);
                if(len==1){
                    return len;
                }
                s-=arr[i];
                i++;
            }
            j++;
        }
        if(len==1e6){
            return 0;
        }
        return len;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends