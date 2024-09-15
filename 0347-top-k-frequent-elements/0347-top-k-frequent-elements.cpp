class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>v;
        
        unordered_map<int,int>m1;
        for(auto it:nums)m1[it]++;
        multimap<int,int>m2;
        for(auto it:m1){
            // m2[it.second]=it.first;
            m2.insert(pair<int,int>(it.second,it.first));
        }
        for(auto it:m2){
            v.push_back(it.second);
        }
        vector<int>ans;
        reverse(v.begin(),v.end());
        for(int i=0;i<k;i++){
            ans.push_back(v[i]);
        }
        
        return ans;
    }
};