//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    long long countSubArrayProductLessThanK(const vector<int>& nums, int n, long long k) {
        long long cnt=0, i=0,j=0, p=1;

        while(j<n){
            p=p*nums[j];

            while(p>=k && i<j){
                p=p/nums[i];
                i++;
            }
            if(p<k){
                cnt+=(j-i+1);
            }
            j++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends