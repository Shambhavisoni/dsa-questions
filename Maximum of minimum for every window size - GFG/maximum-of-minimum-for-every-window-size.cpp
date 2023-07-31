//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector<int> left_nextsmallerElement(int a[], int n){
        vector<int> ans(n);
        stack<int> st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && a[st.top()]>=a[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=0;
            }
            else{
                ans[i]=st.top()+1;
            }
            st.push(i);
        }
        return ans;
    }
    
    vector<int> right_nextsmallerElement(int a[], int n){
        vector<int> ans(n);
        stack<int> st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && a[st.top()]>=a[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=n-1;
            }
            else{
                ans[i]=st.top()-1;
            }
            st.push(i);
        }
        return ans;
    }
    vector <int> maxOfMin(int a[], int n)
    {
        // Your code here
        vector<int> left=left_nextsmallerElement(a, n);
        vector<int> right=right_nextsmallerElement(a, n);
    
        vector<int> b(n);
        for(int i=0;i<n;i++){
            b[i]=right[i]-left[i]+1;
        }
    
        vector<int> c(n+1, -1e9);
        
        for(int i=0;i<n;i++){
            c[b[i]]=max(c[b[i]], a[i]);
        }
    
        vector<int> ans(n, INT_MIN);
    
        for(int i=0;i<n;i++){
            ans[b[i]-1]=max(ans[b[i]-1], a[i]);
        }
    
        for(int i=n-2;i>=0;i--){
            ans[i]=max(ans[i], ans[i+1]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends