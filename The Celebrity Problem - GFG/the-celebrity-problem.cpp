//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    bool isCeleb(vector<vector<int> >& M, int p, int n){
        // celeb knows nobody
        for(int i=0;i<n;i++){
            if(M[p][i]==1){
                return false;
            }
        }
        
        // everybody knows celeb
        for(int i=0;i<n;i++){
            if(i!=p && M[i][p]==0){
                return false;
            }
        }
        
        return true;
    }
    
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        for(int i=0;i<n;i++){
            if(isCeleb(M, i, n)){
                return i;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends