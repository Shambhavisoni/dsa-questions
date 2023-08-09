//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    // bool allPos
	void segregateEvenOdd(int arr[], int n) {
	    // code here
	    int i=0, j=n-1;
	    
	    while(i<j){
	        if(arr[i]%2!=0 && arr[j]%2!=0){
	            j--;
	        }
	        else if(arr[i]%2==0 && arr[j]%2==0){
	            i++;
	        }
	        else if(arr[i]%2==0 && arr[j]%2!=0){
	            i++;
	            j--;
	        }
	        else{
	            swap(arr[i], arr[j]);
	            i++;
	            j--;
	        }
	    }
	    
	    
	    
	    int odd_low=-1, odd_high=n-1, even_low=0, even_high=-1;
	    int ans=-1;
	    for(int k=0;k<n;k++){
	        if(arr[k]%2!=0){
	            odd_low=k;
	            even_high=k-1;
	            break;
	        }
	    }
	   // all odd                              all even
	    if((odd_low==0 && even_high==-2) || (odd_low==-1 && even_high==-1)){
	        return;
	    }
	   
	   sort(arr, arr + even_high - even_low + 1);
	   sort(arr + odd_low, arr + n);
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregateEvenOdd(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends