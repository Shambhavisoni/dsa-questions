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
        int n1=s1.size();
        for(int i=0;i<n1;i++){
            if(s1[i]==s2[0]){
                int j,k=0;
                for(j=i;j<n1;j++){
                    if(s2[k]!=s1[j]){
                        break;
                    }
                    k++;
                }
                if(j==n1){
                    for(j=0;j<i;j++){
                        if(s2[k]!=s1[j]){
                            break;
                        }
                        k++;
                    }
                }
                if(j==i){
                    return true;
                }
            }
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