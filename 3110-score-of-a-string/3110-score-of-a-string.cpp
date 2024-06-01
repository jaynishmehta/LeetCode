class Solution {
public:
    int scoreOfString(string s) {
        char prev=s[0];
        int ans=0;
        for(int i=1;i<s.size();i++){
            ans+= abs(s[i]-prev);
            prev= s[i];
        }
        // return 0;
        return ans;
    }
};