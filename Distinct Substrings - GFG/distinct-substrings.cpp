//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int fun(string s);

int main() {
    int tt;
    string s;
    cin >> tt;
    while (tt--) {
        cin >> s;
        cout<<fun(s)<<endl;
        
    }
    return 0;
}
// } Driver Code Ends


int fun(string s)
{
    //code here
    int i=0, n=s.size();
    set<string> st;
    
    while(i<n-1){
        string a=to_string(s[i])+to_string(s[i+1]);
        st.insert(a);
        i++;
    }
    
    return st.size();
}