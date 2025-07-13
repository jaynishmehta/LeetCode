class Solution {
public:
    bool isvalid(string & s){
        bool t =true;
         for (char c : s) {
            if (!(isalpha(c) || isdigit(c) || c == '_')) {
                return false;
            }
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& bl, vector<bool>& ia) {
        multiset<pair<string,string>>m;
        set<string>s1;
        s1.insert("electronics");
        s1.insert("grocery");
        s1.insert("pharmacy");
        s1.insert("restaurant");
        for(int i=0;i<code.size();i++){
            if(isvalid(code[i]) && ia[i] && code[i].size()>0 && s1.find(bl[i])!=s1.end()){
                // m[bl[i]]=code[i];
                m.insert({bl[i],code[i]});
            }
        }
        vector<string>ans;
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }
};