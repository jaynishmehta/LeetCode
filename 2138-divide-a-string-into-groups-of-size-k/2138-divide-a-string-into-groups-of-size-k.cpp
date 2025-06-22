class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(temp.size()<k){
                temp+=s[i];
            }
            else if(temp.size()==k){
                ans.push_back(temp);
                temp=s[i];
            }
        }
        // if(temp.size()==k){
        //     ans.push_back(temp);
            
        // }
        if(temp.size()<k){
            while(temp.size()<k){
                temp+=fill;
            }
        }
        if(temp.size()==k)ans.push_back(temp);
        return ans;
    }
};