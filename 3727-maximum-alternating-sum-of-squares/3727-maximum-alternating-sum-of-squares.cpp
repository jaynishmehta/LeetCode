class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end(),greater<int>());
        long long sum=0;
        int i=0,j=nums.size()-1;
        while(i<j){
            sum+= nums[i]*nums[i];
            // cout<<i<<" ";
            i++;
            sum-= nums[j]*nums[j];
            // cout<<j<<" ";
            j--;
        }
        if(i==j)sum+=nums[i]*nums[i];
        return sum;
    }
};