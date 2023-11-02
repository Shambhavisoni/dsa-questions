//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        int n1=s1.size(), n2=s2.size();
        if(n1!=n2){
            return false;
        }
        queue<char> q1, q2;
        for(int i=0;i<n1;i++){
            q1.push(s1[i]);
            q2.push(s2[i]);
        }
        
        while(n2!=0){
            char ch=q2.front();
            q2.pop();
            q2.push(ch);
            if(q1==q2){
                return true;
            }
            n2--;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends