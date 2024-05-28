class Solution {
public:
    int equalSubstring(string s, string t, int maxcost) {
        vector<int>v;
        for(int i=0;i<s.size();i++){
            v.push_back(abs(s[i]-t[i]));
        }
        int i=0,j=0;
        long long sum=0;
        int maxi=0;
        int cnt=0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            if(sum<=maxcost){
                maxi= max(maxi,(i-j+1));
            }
            else{
                sum-=v[j];
                j++;
            }
        }
        maxi=max(maxi,(i-j+1));
        return maxi;
    }
};