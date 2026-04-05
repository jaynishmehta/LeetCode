class Solution {
public:

    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj, stack<int>& st){

        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, vis, pathVis, adj, st)) return true;
            }
            else if(pathVis[it]){
                return true;   // cycle detected
            }
        }

        pathVis[node] = 0;
        // st.push(node);

        return false;
    }

    bool canFinish(int courses, vector<vector<int>>& pr) {

        vector<vector<int>> adj(courses);

        for(int i = 0; i < pr.size(); i++){
            adj[pr[i][1]].push_back(pr[i][0]);
        }

        vector<int> vis(courses, 0);
        vector<int> pathVis(courses, 0);
        stack<int> st; // no need for topological arrangements in this ques

        for(int i = 0; i < courses; i++){
            if(!vis[i]){
                if(dfs(i, vis, pathVis, adj, st)) return false;
            }
        }

        return true;
    }
};