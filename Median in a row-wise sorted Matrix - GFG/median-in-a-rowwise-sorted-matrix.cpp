//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int cnt(vector<vector<int>> &matrix, int R, int C, int x){
        int low=0, high=C-1, ans=-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[R][mid]<x){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans+1;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here   
       int mini=INT_MAX, maxi=INT_MAX, ans;
        for(int i=0;i<R;i++){
            mini=min(matrix[i][0], mini);
            maxi=max(matrix[i][C-1], maxi);
        }
        int low=mini, high=maxi;
        int med=((R*C)/2);
        while(low<=high){
            int mid=low+(high-low)/2;
            int c=0;
            for(int i=0;i<R;i++){
                c+=cnt(matrix, i, C, mid);
            }
            if(c<=med){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends