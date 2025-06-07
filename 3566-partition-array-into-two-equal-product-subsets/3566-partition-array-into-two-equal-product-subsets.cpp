class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        
        for(int i=0;i<(1<<nums.size());i++){
            long long p1=1,p2=1;
            bool valid = true;
            for(int j=0;j<nums.size();j++){
                if(i & (1<<j)){
                    if (nums[j] != 0 && p1 > target / nums[j]) {
                        valid = false;
                        
                        break;
                    }
                    p1*=nums[j];
                }
                else{
                    if(nums[j]!=0 &&  p2> target/nums[j]){
                        valid = false;
                        break;
                    }
                     p2*=nums[j];
                }

            }
            if(valid==true && p1==target && p2==target)return true;
            
        }
        return false;
    }
};