class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=0;
        for(int i=0;i<nums.size();i++){
            if(n<0)return false;
            else if(nums[i]>n){
                n=nums[i];
            }
            n-=1;
        }
        return true;
    }
};