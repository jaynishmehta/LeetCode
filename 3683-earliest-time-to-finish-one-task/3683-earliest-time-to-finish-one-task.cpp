class Solution {
public:
    int earliestTime(vector<vector<int>>& t) {
        int maxi=INT_MAX;
        for(int i=0;i<t.size();i++){
            int temp = t[i][0]+t[i][1];
            maxi = min(maxi,temp);
        }
        return maxi;
    }
};