class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        // int i= n-1;
        // int j= i-1;
        int ind=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
                ind=i;
                break;
            }
        }
        // cout<<ind<<endl;
        if(ind<0){
            sort(nums.begin(),nums.end());
            
        }
        
        else{
            for(int k=n-1;k>ind;k--){
                if(nums[k]>nums[ind]){
                    // cout<<nums[k]<<endl;
                    swap(nums[ind],nums[k]);
                    // cout<<nums[k];
                    break;
                }
            }
            sort(nums.begin()+ind+1,nums.end());
        }
    }
};