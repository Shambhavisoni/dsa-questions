//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> pattern(int n){
        // code here
        vector<string> ans;
        int spaces=0;
        for(int i=0;i<n;i++){
            string r="";
            for(int j=0;j<spaces;j++){
                r+="-";
            }
            spaces+=2;
            ans.push_back(r);
        }
        
        int k=0, cnt=1;
        for(int i=n-1;i>=0;i--){
            for(int j=0; j<=i; j++){
                ans[k]+=to_string(cnt);
                ans[k]+="*";
                cnt++;
            }
            k++;
        }
        
        k=n-1;
        int len=2;
        for(int i=1; i<=n; i++){
            for(int j=i; j<=len-1; j++){
                ans[k]+=to_string(cnt);
                if(j!=len-1)
                ans[k]+="*";
                cnt++;
            }
            len+=2;
            k--;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<string> ans = ob.pattern(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<"\n";
    }
    return 0;
}
// } Driver Code Ends