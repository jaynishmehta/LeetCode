class Solution {
    void dfs(int curr,int &nodes,int &edges,vector<vector<int>>&adj,vector<bool>&v){
        nodes++;
        v[curr]=true;
        for(int  & nbr:adj[curr]){
            edges++;
            if(!v[nbr])dfs(nbr,nodes,edges,adj,v);
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int components=0;
        vector<bool>v(n,false);
        for(int i=0;i<n;i++){
            if(!v[i]){
                //count edges and nodes
                int edges=0;
                int nodes =0;
                dfs(i,nodes,edges,adj,v);
                if(edges== (nodes*(nodes-1)))components++;
            }
        }
        return components;
    }
};