//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[1]<b[1]){
            return true;
        }
        else if(a[1]==b[1]){
            return a[2]<b[2];
        }
        return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<vector<int>> jobs;
        
        for(int i=0;i<n;i++){
            jobs.push_back({start[i], end[i], i});
        }
        
        sort(jobs.begin(), jobs.end(), comp);
        
        int t=0, c=0;
        
        for(auto it:jobs){
            if(t < it[0]){
                t=it[1];
                c++;
            }
        }
        return c;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends