class Solution {
public:
    bool dfs(int node,vector<int>&v,vector<int>&p,vector<vector<int>>&adj){
        v[node]=1;
        p[node]=1;
        for(auto it:adj[node]){   // checking the adjacennt node
            if(!v[it]){
                // p=it;
                if(dfs(it,v,p,adj))return true;  // if 
            }
            else if(v[it]==1 && p[it]==1) {
                return true;
            }
        }
        p[node]=0;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n, vector<int>());
        // vector<int> degree(n, 0);
        for (auto &p: pre) {
            adj[p[1]].push_back(p[0]);
            // degree[p[0]]++;
        }
        
        vector<int>v(adj.size(),0);
        vector<int>p(adj.size(),0);
        for(int i=0;i<adj.size();i++){
            if(!v[i]){
                if(dfs(i,v,p,adj))return false;
            }
        }
        return true;
    }
};