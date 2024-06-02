class Solution {
public:
    int minimumChairs(string s) {
        int maxi=0;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='E'){
                cnt++;
                maxi=max(maxi,cnt);
            }
            else{
                cnt--;
            }
        }
        return maxi;
    }
};