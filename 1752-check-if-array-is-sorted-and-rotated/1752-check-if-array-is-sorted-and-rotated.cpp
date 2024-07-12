class Solution {
public:
    bool check(vector<int>& nums) {
        int bimp=0;
        int n= nums.size();
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                bimp=i;
                break;
            }
        }
        
        vector<int>num(n,0);
        for(int i=0;i<n;i++){
            num[i]= nums[(i+bimp)%n];
        }
        for(int i=1;i<n;i++){
            if(num[i-1]>num[i])return false;
        }
        return true;
    }
};