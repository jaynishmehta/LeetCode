class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int h= nums.size()-2;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]==nums[mid^1]){ //check if mid is even its odd should be equal and vice versa (even,odd,even,odd)
                l= mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return nums[l];
    }
};