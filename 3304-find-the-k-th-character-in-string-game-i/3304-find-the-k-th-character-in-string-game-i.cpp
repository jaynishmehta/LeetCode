class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.size()<k){
            string s1= "";
            for(auto it:s){
                s1+=('a'+((it-'a')+1)%26);
            }
            s+=s1;
        }
        // cout<<s;
         return s[k-1];
    }
};