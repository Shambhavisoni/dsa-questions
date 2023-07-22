class Solution {
public:
    bool isPos(vector<int>& nums, int k, int mid){
        int n=nums.size(), s=0, c=1;
        
        for(int i=0;i<n;i++){
            if(nums[i]>mid){
                return false;
            }
            if(s+nums[i]>mid){
                s=nums[i];
                c++;
            }
            else{
                s+=nums[i];
            }
        }
        return c<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size(), sum=0, mini=INT_MAX, ans;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mini=min(mini, nums[i]);
        }
        
        int low=mini, high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPos(nums, k, mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};