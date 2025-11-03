class Solution {
public:
    int minCost(string c, vector<int>& t) {
        long long int n=c.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return solve()
        long long int i=1;
        long long int cnt=0;
        long long int prev= 0;
        while(i<n){
            if(c[i]==c[prev]){
                long long int ind=0;
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