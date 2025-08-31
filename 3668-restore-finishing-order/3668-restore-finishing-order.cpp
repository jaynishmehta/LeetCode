class Solution {
public:
    vector<int> recoverOrder(vector<int>& o, vector<int>& f) {
        unordered_map<int,int>m;
        for(auto it:f){
            m[it]++;
        }
        vector<int>ans;
        for(int i=0;i<o.size();i++){
            if(m.find(o[i])!=m.end()){
                ans.push_back(o[i]);
            }
        }
        return ans;
    }
};