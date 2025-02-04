class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum=nums[0];
        int maxi= sum;
        int p=nums[0];
        for(int i=1;i<nums.size();i++){
            if(p<nums[i]){
                sum+=nums[i];
                p=nums[i];
                maxi= max(maxi,sum);
            }
            else{
                p= nums[i];
                maxi= max(maxi,sum);
                sum= nums[i];
            }
            cout<<sum<<" ";
        }
        return maxi;
    }
};