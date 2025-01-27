class Solution {
public:
    int countSubstrings(string s) {
        int cnt=0;
        int l=0,r=0;
        int l_pointer=0;
        for(int i=0;i<s.size();i++){
            // odd palindrome
            l=i,r=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                cnt++;
                l_pointer=l;
                l--;
                r++;
            }
            // even palindrome
            l=i,r=i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                cnt++;
                l_pointer=l;
                l--;
                r++;
            }
        }
        return cnt;
    }
};