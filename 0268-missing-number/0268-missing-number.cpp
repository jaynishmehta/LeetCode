class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size=nums.size();
        int j =0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<size;i++){
            if(nums[i]==j){
                j++;
            }
            else{
                return j;
            }
        }
        return size;
    }
};