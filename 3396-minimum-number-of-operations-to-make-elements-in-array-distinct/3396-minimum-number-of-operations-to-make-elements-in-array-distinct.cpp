class Solution {
public:
    bool isdistinct(vector<int>&nums,int i){
        set<int>s;
        if(i>=nums.size())return false;
        for(int j = i;j<nums.size();j++){
            s.insert(nums[j]);
        }
        if(s.size()==(nums.size()-i))return true;
        else return false;
    }
    int minimumOperations(vector<int>& nums) {
        int cnt=0,i=0;
        while(i< nums.size()){
            if(isdistinct(nums,i)){
                return cnt;
            }
            else{
                i+=3;
                cnt++;
            }
        }
        return cnt;
    }
};