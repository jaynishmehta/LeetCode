class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int dir=1;
        long long int cnt=0;
        while(i<j){
            long long int temp = nums[i]+nums[j];
            if(temp<=upper){
                cnt+= (j-i);
                i++;
            }
            else{
                j--;
            }
        }
        
        i=0,j=nums.size()-1;
        long long int cnt1=0;
        while(i<j){
            long long temp= nums[i]+nums[j];
            if(temp<lower){
                cnt1+=(j-i);
                i++;
            }
            else{
                j-=1;
            }
        }
        // Return the difference between pairs within the upper bound and those below the lower bound.
        return cnt-cnt1;
    }
};