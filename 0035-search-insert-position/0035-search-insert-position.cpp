class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size()-1;
        int ans=-1;
        if(target>nums[nums.size()-1])return nums.size();
        while(l<=h){
            int mid= (l+h)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]<target){
                ans=max(ans,mid);
                l=mid+1;
            }
            else{
                ans= mid;
                // ans=min(ans,mid);
                h=mid-1;
            }
        }
        
        return ans;
    }
};