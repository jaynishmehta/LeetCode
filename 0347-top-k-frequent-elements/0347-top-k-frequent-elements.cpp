class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(auto it:nums)m[it]++;
        priority_queue<pair<int,int>>pq;
        for(auto it:m){
            pair<int,int>p;
            p={it.second,it.first};
            pq.push(p);
        }
        vector<int>v;
        
        for(int i=0;i<k;i++){
            int x= pq.top().second;
            v.push_back(x);
            pq.pop();
        }
        return v;
    }
};