class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>freq;
        for(auto it:s)freq[it]++;
        set<char>s1;
        string st="";
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            st+=s[i];
            s1.insert(s[i]);
            freq[s[i]]--;
            if(freq[s[i]]==0)s1.erase(s[i]);
            if(s1.size()==0){
                ans.push_back(st.size());
                st="";
            }
        }
        // ans.push_back()
        return ans;
    }
};