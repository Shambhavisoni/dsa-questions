class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        
        // if only one element in matrix
        if(m==1 && n==1){
            return {0,0};
        }
        
        int low=0, high=m-1;
        
        while(low<=high){
            int c=0, maxi=-1, mid=low+(high-low)/2;
            // find out max element in mid row
            for(int i=0;i<n;i++){
                if(maxi<mat[mid][i]){
                    maxi=mat[mid][i];
                    c=i;
                }
            }
            
            // if mid row is first row
            if(mid==0 && mat[mid][c]>mat[mid+1][c]){
                return {mid,c};
            }
            else if(mid==0 && mat[mid][c]<mat[mid+1][c]){
                low=mid+1;
                continue;
            }
            
            // if mid row is last row
            if(mid==m-1 && mat[mid][c]>mat[mid-1][c]){
                return {mid,c};
            }
            else if(mid==m-1 && mat[mid][c]<mat[mid-1][c]){
                high=mid-1;
                continue;
            }
            
            // now check if mid is in any other row
            
            if(mat[mid][c] > mat[mid+1][c] && mat[mid][c] > mat[mid-1][c]){
                return {mid,c};
            }
            else if(mat[mid][c]<mat[mid+1][c]){
                low=mid+1;
            }
            else if(mat[mid][c]<mat[mid-1][c]){
                high=mid-1;
            }
        }
        return {-1,-1};
    }
};