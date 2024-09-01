class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<long long int,int>m;
        for(auto it:nums){
            m[it]++;
            if(m[it]>1)return true;
        }
        return false;
    }
};