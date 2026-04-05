class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj, stack<int>& st){

        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, pathVis, adj, st);
            }
            // else if(pathVis[it]){
            //     break;   // cycle detected
            // }
        }

        pathVis[node] = 0;
        st.push(node);

        // return false;
    }
    vector<int> findOrder(int courses, vector<vector<int>>& pr) {
        // we are checking path are visited i.e cycle exists or not, then using topo;
        vector<vector<int>> adj(courses);

        for(int i = 0; i < pr.size(); i++){
            adj[pr[i][1]].push_back(pr[i][0]);
        }
        
        vector<int> vis(courses, 0);
        vector<int> pathVis(courses, 0);
        stack<int> st; // no need for topological arrangements in this ques

        for(int i = 0; i < courses; i++){
            if(!vis[i]){
                dfs(i, vis, pathVis, adj, st);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};