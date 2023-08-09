//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int getCount(int n) {
        // code here
        // explaination written in blue diary(25 june pg)
        int cnt=0;
        for(int k=2;2 * n > (k*(k-1));k++){
            int numerator=n - ((k *(k-1))/2);
            int denominator=k;

            if(numerator % denominator == 0){
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