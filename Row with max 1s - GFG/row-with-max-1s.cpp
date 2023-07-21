//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > matrix, int n, int m) {
	    // code here
	    int maxi=0, row=-1;
        for(int i=0;i<n;i++){
            int low=0, high=m-1, ans=m;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(matrix[i][mid]==1){
                    ans=mid;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            int len=m-ans;
            if(maxi<len){
                maxi=len;
                row=i;
            }
        }
        return row;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends