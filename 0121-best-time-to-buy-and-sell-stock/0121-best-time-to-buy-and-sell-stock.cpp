class Solution {
public:
    int maxProfit(vector<int>& p) {
        int prev= p[0];
        int maxi=INT_MIN;
        for(int i=1;i<p.size();i++){
            if(p[i]<prev){
                prev= p[i];
            }
            maxi = max(maxi,p[i]-prev);
        }
        if(maxi==INT_MIN)return 0;
        return maxi;
    }
};