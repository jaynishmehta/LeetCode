class Solution {
public:
    int largestAltitude(vector<int>& g) {
        int maxi=0;
        int curr=0;
        for(int i=0;i<g.size();i++){
            curr=curr+g[i];
            maxi= max(curr,maxi);
        }
        return maxi;
    }
};