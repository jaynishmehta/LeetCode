class Solution {
public:
    int minCost(string c, vector<int>& t) {
        int n=c.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return solve()
        int i=1;
        int cnt=0;
        char prev= 0;
        while(i<n){
            if(c[i]==c[prev]){
                int ind=0;
                if(t[i]<t[prev]){
                    ind=i;
                    i++;
                }
                else{
                    ind=prev;
                    prev= i;
                    i++;
                }
                cnt+=t[ind];
                
            }
            else {
                prev=i;
                i++;
            }
        }
        return cnt;
    }
};