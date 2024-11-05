class Solution {
public:
    int minChanges(string s) {
        int cnt=0;
        char prev=s[0];
        for(int i=1;i<=s.size()-1;i+=2){
            if(s[i]!=prev){
                cnt++;
            }
            if(i<s.size()-1){
                prev=s[i+1];
            }
            
        }
        return cnt;
    }
};