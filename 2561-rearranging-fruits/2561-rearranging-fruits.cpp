class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        unordered_map<int,int>m;
        int mini=INT_MAX;
        for(auto it:b1){
            m[it]++;
            mini= min(mini,it);
            // m1[it]++;
        }
        for(auto it:b2){
            m[it]--;
            mini= min(mini,it);
            // m2[it]--;
        }
        long long cost=0;
        vector<int>v;
        for(auto it:m){
            if(it.second %2!=0)return -1;
            for(int i=0;i<abs(it.second)/2;i++){
                v.push_back(it.first);
                // cout<<it.first<<" ";
            }
            
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()/2;i++){
            cost+= min(v[i],2*mini);
            cout<<v[i]<<" ";
        }
        return cost;
    }
};  