//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*
str: string in which pattern we have to find pattern.
text: pattern needs to searched.
*/

bool searchPattern(string h, string ne)
{
    // your code here
    if(h.size()<ne.size()){
        return 0;
    }
    for(int i=0;i<h.size();i++){
        if(h[i]==ne[0]){
            int pos=i,j=0;
            while(j<ne.size() && h[i]==ne[j]){
                i++;
                j++;
            }
            if(j==ne.size()){
                return 1;
            }
            else{
                i=pos;
            }
        }
    }
    return 0;
}



//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    
    while(t--)
    {
        string str, pat;
        cin>>str;
        cin>>pat;
        
        if(searchPattern(str, pat) == true)
            cout << "Present" <<endl;
        else cout << "Not present" <<endl;
    }
}


// } Driver Code Ends