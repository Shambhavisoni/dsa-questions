//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void helper(stack<int>&st, int mid, int& cnt){
        if(cnt==mid){
            st.pop();
            return;
        }
        cnt++;
        int x=st.top();
        st.pop();
        
        helper(st, mid, cnt);
        
        st.push(x);
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        int cnt=1, mid=ceil((sizeOfStack+1)/2.0);
        
        helper(s, mid, cnt);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends