class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto it:nums){
            m[it]++;
        }
        multimap<int,int>mm;
        for(auto it:m){
            // mm[it.second]=it.first;
            mm.insert({it.second,it.first});
        }
        //times- ele
        vector<int>v;
        for(auto it:mm){
            int x= it.first;
            while(x>0){
                v.push_back(it.second);
                x--;
            }
        }
        return v;

    }
};