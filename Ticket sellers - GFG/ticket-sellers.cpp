//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    const int mod=1e9+7;
    int maxAmount(int N, int k, int A[])
    {
        // code here
        priority_queue<int> pq;
        for(int i=0;i<N;i++){
            pq.push(A[i]);
        }
        
        int amt=0;
        while(k!=0){
            int cost=pq.top();
            pq.pop();
            amt =((amt%mod) + (cost%mod))%mod;
            cost--;
            k--;
            if(cost!=0){
                pq.push(cost);
            }
        }
        return amt;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, K;
        cin>>N>>K;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.maxAmount(N, K, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends