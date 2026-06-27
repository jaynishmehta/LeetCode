class Solution {
public:
    void dfs(int node,vector<int>&v,vector<vector<int>>& c,int cnt){
        v[node]=1;
        // cnt++;
        for(int neig=0;neig<c.size();neig++){
            if(c[node][neig]==1 && !v[neig]){
                dfs(neig,v,c,cnt);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& c) {
        int cnt=0;
        vector<int>v(c.size(),0);
        for(int i=0;i<c.size();i++){
            if(!v[i]){
                cnt++;
                dfs(i,v,c,cnt);
            }
        }
        return cnt;
    }
};