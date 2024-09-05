class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini= 1e7;
        int low=0;
        int high= nums.size()-1;
        while(low<=high){
            int mid= (low+high)/2;
            if(nums[mid]>nums[high]){
                if(nums[high]<nums[low]){
                    mini= min(mini,nums[high]);
                    low= mid+1;
                }
                else{
                     mini= min(mini,nums[low]);
                    high= mid-1;
                }
            }
            else{
                if(nums[high]<nums[mid]){
                    mini= min(mini,nums[high]);
                    low= mid+1;
                    
                }
                else{
                    mini= min(mini,nums[mid]);
                    high=mid-1;
                }
            }
        }
        return mini;
    }
};