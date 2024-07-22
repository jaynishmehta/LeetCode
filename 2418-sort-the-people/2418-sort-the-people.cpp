class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        multimap<int,string>m;
        for(int i=0;i<names.size();i++){
            // m[heights[i]]=names[i];
            m.insert(pair<int, string>(heights[i], names[i]));
        }
        vector<string>ans;
        for(auto it:m){
            string x= it.second;
            ans.push_back(x);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};