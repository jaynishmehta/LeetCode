class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0;
        int maxf=INT_MIN;
        int maxi=INT_MIN;
        vector<int>v(26,0);
        while(i<s.size()){
            v[s[i]-'A']++;
            maxf= max(maxf,v[s[i]-'A']);
            if((i-j+1)-maxf<=k){
                maxi = max(maxi,(i-j+1));
            }
            else{
                v[s[j]-'A']--;
                j++;
            }
            i++;
        }
        return maxi;
    }
};