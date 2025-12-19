class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=1;
        int sum=nums[0];
        int maxi=nums[0];
        while(i<nums.size()){
            sum+=nums[i];
            if(sum<0){
                // maxi= max(maxi,nums[i]);
                sum=max(nums[i],0);
            }
            else maxi= max(maxi,sum);
            i++;
            cout<<maxi<<endl;
        }
        maxi= max(maxi,sum);
        return maxi;
    }
};