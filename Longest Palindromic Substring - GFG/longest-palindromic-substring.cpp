//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string S){
        // code here 
        int n=S.size(), maxi=1, start=0;
        
        for(int i=0;i<n;i++){
            int l=i-1, r=i+1;
            while(l>=0 && r<n && S[l]==S[r]){
                int len=r-l+1;
                if(maxi<len){
                    maxi=len;
                    start=l;
                }
                l--;
                r++;
            }
            l=i, r=i+1;
            while(l>=0 && r<n && S[l]==S[r]){
                int len=r-l+1;
                if(maxi<len){
                    maxi=len;
                    start=l;
                }
                l--;
                r++;
            }
        }
        
        string ans= S.substr(start, maxi);
        return ans;
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends