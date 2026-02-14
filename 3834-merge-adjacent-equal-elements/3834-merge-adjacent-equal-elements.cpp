class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long int>v;
        for(int i=0;i<nums.size();i++){
            int curr= nums[i];
            while(!v.empty() && v.back()==curr){
                curr *=2;
                v.pop_back();
            }
            v.push_back(curr);
        }
        return v;
    }
};