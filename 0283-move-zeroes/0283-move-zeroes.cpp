class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt=0;
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=0){
                nums[i]=nums[j];
                i++;
                cnt++;
            }
        }
        for(int j=cnt;j<nums.size();j++){
            nums[j]=0;
        }
        
        
    }
};