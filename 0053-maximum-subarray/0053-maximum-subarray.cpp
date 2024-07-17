class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<0){
                sum=0;
            }
            else if(sum>maxi){
                maxi=sum;
            }
        }
        if(maxi<=0){
            for(int i=0;i<nums.size();i++){
                maxi=max(maxi,nums[i]);
            }
        }
        return maxi;
    }
};