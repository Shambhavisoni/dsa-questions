//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int getCount(int N) {
        // code here
        int cnt=0;
        for(int k=2;2*N>k*(k-1);k++){
            int num = N - ((k*(k-1))/2);
            int denum = k;
            
            if(num % denum == 0){
                cnt++;
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.getCount(N) << endl;
    }
    return 0;
}
// } Driver Code Ends