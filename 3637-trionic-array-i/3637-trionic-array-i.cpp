class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p=0,q=0;
        for(int i=1;i<nums.size()-1;i++){
            if((nums[i-1]<nums[i] && nums[i]>nums[i+1])){
                p=i;
            }
            else if(nums[i-1]>nums[i] && nums[i]<nums[i+1]){
                q=i;
            }
            
        }
        bool ans1=true;
        for(int i=1;i<=p;i++){
            if(nums[i-1]>=nums[i])return false;
        }
        bool ans2=true;
        for(int i=q;i<nums.size()-1;i++){
            if(nums[i+1]<=nums[i])return false;
        }
        if(p==0 || q==0)return false;
        if(p>=q)return false;
        return true;
    }
};