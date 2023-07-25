//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int, int> mp;
        
        int s=0, tar=0, maxLen=0;
        for(int i=0;i<n;i++){
            s+=A[i];
            if(s==tar){
                int len=i+1;
                maxLen=max(maxLen, len);
            }
            else if(mp.find(s-tar)!=mp.end()){
                int len=i-mp[s-tar];
                maxLen=max(maxLen, len);
            }
            else{
                mp[s]=i;
            }
        }
        return maxLen;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends