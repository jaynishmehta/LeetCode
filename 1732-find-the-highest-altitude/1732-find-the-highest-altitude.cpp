class Solution {
public:
    int largestAltitude(vector<int>& g) {
        vector<int>v(g.size()+1,0);
        for(int i=0;i<g.size();i++){
            v[i+1]=v[i]+g[i];
        }
        int maxi = -100;
        for(int i=0;i<v.size();i++){
            if(v[i]>maxi)maxi=v[i];
        }
        return maxi;
    }
};