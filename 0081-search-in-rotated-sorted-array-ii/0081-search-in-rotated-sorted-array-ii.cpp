class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int l=0;
        int h= nums.size()-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]==target)return true;
            
            if(nums[mid]==nums[l]&&nums[mid]==nums[h]){  //extra condition we have added
                l=l+1;
                h=h-1;
                continue;
            }
            
            if(nums[mid]>nums[h]){ //left part is sorted
                if(target>=nums[l] && target<=nums[mid]) {
                    h= mid-1;
                }
                else{
                    l= mid+1;
                }
            }
            else {//right part is sorted
                if(target>=nums[mid] && target<=nums[h]){
                    l= mid+1;
                }
                else{
                    h=mid-1;
                }
            }
            
        }
        return false;
    }
};