class Solution {
public:
    bool detect(int i, vector<vector<int>>&adj,vector<int>&v){
        v[i]=1;
        queue<pair<int,int>>q;
        q.push({i,-1});
        while(!q.empty()){
            int parent=q.front().second;
            int node= q.front().first;
            q.pop();
            for(auto it:adj[i]){
                if(!v[it]){
                    v[it]=1;
                    q.push({it,i});
                }
                else if(it!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool canFinish(int courses, vector<vector<int>>& pr) {
        vector<vector<int>>adj(courses,vector<int>());
        for(int i=0;i<pr.size();i++){
            adj[pr[i][1]].push_back(pr[i][0]);
        }
        vector<int>v(adj.size(),0);
        for(int i=0;i<adj.size();i++){
            if(!v[i]){
                if(detect(i,adj,v))return false;
            }
        }
        return true;
    }
};