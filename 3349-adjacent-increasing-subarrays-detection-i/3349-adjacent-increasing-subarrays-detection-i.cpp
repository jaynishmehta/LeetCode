class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int c1=1;
        if(k==1){
            return true;
            // else return false;
        }
        for(int i=0;i<nums.size()-k-1;i++){
            if((nums[i+1]-nums[i]>0)&&(nums[i+k+1]-nums[i+k]>0)){
                c1++;
                if(c1==k)return true;
            }
            else c1=1;
        }
        return false;
    }
};