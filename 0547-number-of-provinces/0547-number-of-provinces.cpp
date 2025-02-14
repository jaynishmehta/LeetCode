class Solution {
public:
    void dfs(int node,vector<int>&v,vector<vector<int>>& is_c){
            // cout<<node<<" ";
            v[node]=1;
             for(int neighbor = 0; neighbor < is_c.size(); neighbor++) {
                if (is_c[node][neighbor] == 1 && !v[neighbor]) {  // Check if there's a connection
                    dfs(neighbor, v, is_c);
                }
            }
        }
    int findCircleNum(vector<vector<int>>& is_c) {
        vector<int>v(is_c.size(),0);
        int cnt=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==0){
                cnt++;
                dfs(i,v,is_c); // pass index not value i.e v[i] just i
            }
        }
        return cnt;
    }
};
