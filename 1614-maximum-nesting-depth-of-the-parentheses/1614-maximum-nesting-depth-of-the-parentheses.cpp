class Solution {
public:
    int maxDepth(string s) {
        int left_bracket=0;
        int right_bracket=0;
        int i=-1;
        int maxi=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')left_bracket++;
            else if(s[i]==')')right_bracket++;
            maxi= max(maxi,left_bracket - right_bracket);
        }
        return maxi;
    }
};