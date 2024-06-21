class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        int mini=1e7;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]>nums[h]){ // left half is sorted
                if(nums[l]>nums[h]){
                    mini= min(mini,nums[h]);
                    l= mid+1;
                }
                else{
                    mini= min(mini,nums[l]);
                    h= mid-1;
                }
                
            }
            else{  //right half is sorted
                if(nums[mid]>nums[l]){
                    mini= min(mini,nums[l]);
                    l= mid+1;
                }
                else{
                    mini= min(mini,nums[mid]);
                    h=mid-1;
                }
            }
            
        }
        return mini;
    }
};