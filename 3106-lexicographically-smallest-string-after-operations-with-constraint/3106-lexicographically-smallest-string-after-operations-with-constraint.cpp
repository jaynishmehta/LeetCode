class Solution {
public:
    string getSmallestString(string s, int k) {
        int i=0;
        while(i<s.size() && k>0){
            int diff= min(s[i]-'a',26-(s[i]-'a'));
            if(diff<=k){
                s[i]='a';
                k-=diff;
            }
            else{
                s[i]=s[i]-k;
                k=0;
            }
            i++;
        }
        return s;
    }
};