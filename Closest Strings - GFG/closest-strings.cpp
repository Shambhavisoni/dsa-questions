//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int shortestDistance(vector<string> &s, string word1, string word2)
	{
		// Your code goes here
		int n=s.size(), mini=INT_MAX, idx1=-1, idx2=-1;
		
		for(int i=0;i<n;i++){
		    if(s[i]==word1){
		        idx1=i;
		    }
		    if(s[i]==word2){
		        idx2=i;
		    }
		    
		    if(idx1!=-1 && idx2!=-1){
		        int diff=abs(idx1-idx2);
		        mini=min(mini, diff);
		    }
		}
		
		return mini;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;

   		vector<string> s(n);
   		for(int i = 0; i < n; i++)
   			cin >> s[i];

   		string word1, word2;

   		cin >> word1 >> word2;
   		
   		Solution ob;

   		cout << ob.shortestDistance(s, word1, word2) << "\n";
   	}

    return 0;
}
// } Driver Code Ends