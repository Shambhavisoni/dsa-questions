//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int A[], int n) {
        // code here
        int mini=-1;
        map<int,int> mp;
        for(int i=n-1;i>=0;i--){
            if(mp.find(A[i])!=mp.end()){
                mini=i+1;
            }
            else{
                mp[A[i]]=1;
            }
        }
        return mini;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i) cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}

// } Driver Code Ends