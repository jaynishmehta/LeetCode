class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int>m;
        string s="";
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=' '){
                s+=s1[i];
            }
            else{
                m[s]++;
                s="";
            }
            
        }
        if (!s.empty()) {  // Handle the last word
            m[s]++;
        }
        s="";
        
        
        for(int i=0;i<s2.size();i++){
            if(s2[i]!=' '){
                s+=s2[i];
            }
            else{
                m[s]++;
                s="";
            }
            
        }
        
        if (!s.empty()) {  // Handle the last word
            m[s]++;
        }
        
        vector<string>v;
        for(auto it:m){
            if(it.second==1){
                v.push_back(it.first);
            }
        }
        return v;
    }
};