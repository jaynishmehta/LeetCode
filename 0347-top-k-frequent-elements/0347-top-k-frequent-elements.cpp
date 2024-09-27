class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>v;
        
        unordered_map<int,int>m1;
        for(auto it:nums)m1[it]++;
        priority_queue<pair<int,int>>pq;
        for(auto it:m1){
            // pair<int,int>p1 = {it.second,it.first};
            // pq.push(pair<int,int>(it.second,it.first)); can be inserted in many ways
            pq.push({it.second,it.first});
        }
        for(int i=0;i<k;i++){
             v.push_back(pq.top().second);
            pq.pop();
           
        }
        return v;
    }
};