#define ll long long
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        ll xorr= 0;
        for(auto it: nums){
            xorr^=it;
        }
        ll right_set = xorr & ~(xorr-1);
        vector<int>v;
        ll xor1=0,xor2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&right_set){
                xor1^=nums[i];
            }
            else{
                xor2^=nums[i];
            }
        }
        if(xor1>xor2){
            v.push_back(xor2);
            v.push_back(xor1);
        }
        else{
            v.push_back(xor1);
            v.push_back(xor2);
        }
        return v;
    }
};