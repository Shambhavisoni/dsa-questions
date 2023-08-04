//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> uniqueNumbers(int L,int R)
    {
        // Write Your Code here
        vector<int> ans;
        map<int,int> mp;
        for(int i=L;i<=R;i++){
            int num=i;
            bool flag=true;
            while(num>0){
                int y=num%10;
                if(mp.find(y)!=mp.end()){
                    flag=false;
                    break;
                }
                mp[y]++;
                num=num/10;
            }
            mp.clear();
            if(flag){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l,r ;
        cin >> l >> r;
		Solution ob;
		vector<int> numbers = ob.uniqueNumbers(l,r);
		
		for(int num : numbers){
		   cout<<num<<" ";
		}
		cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends