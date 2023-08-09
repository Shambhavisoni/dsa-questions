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
		int n=s.size();
		map<string, vector<int>> mp;
		for(int i=0;i<n;i++){
		    if(s[i]==word1){
		        mp[s[i]].push_back(i);
		    }
		    if(s[i]==word2){
		        mp[s[i]].push_back(i);
		    }
		}
		int mini=INT_MAX;
		for(auto it:mp[word1]){
		    for(auto a:mp[word2]){
		        int diff=abs(it-a);
		        mini=min(mini,diff);
		    }
		}
		return mini;
	}
};

// 		int i=0, j=0, n=s.size();
// 		while(i<n && j<n && s[i]!=word1){
// 		    i++;
// 		    j++;
// 		}
// 		int mini=INT_MAX;
// 		for(int k=j;k<n;k++){
// 		    if(s[k]==word1){
// 		        i=k;
// 		    }
// 		    else if(s[k]==word2){
// 		        mini=min(mini, k-i+1);
// 		        i=j;
// 		        while(i<n && j<n && s[i]!=word1){
//         		    i++;
//         		    j++;
//         		}
// 		    }
// 		}
// 		return mini;

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