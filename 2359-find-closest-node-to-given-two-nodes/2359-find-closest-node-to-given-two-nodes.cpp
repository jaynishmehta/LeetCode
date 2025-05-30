class Solution {
public:
    
    void dfs(int node,vector<bool>&v,vector<int>&d,vector<int>&edges){
        v[node]=true;

        int t= edges[node];
        if(t!=-1 && !v[t] ){
            v[t]=true;
            d[t]=1+ d[node];
            dfs(t,v,d,edges);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<bool>vis1(edges.size(),false);
        vector<bool>vis2(edges.size(),false);
        vector<int>d1(edges.size(),INT_MAX);
        vector<int>d2(edges.size(),INT_MAX);
        vis1[node1]=true;
        vis2[node2]=true;
        d1[node1]=0;
        d2[node2]=0;
        dfs(node1,vis1,d1,edges);
        dfs(node2,vis2,d2,edges);

        int mini=INT_MAX;
        int result =-1;
        for(int i=0;i<edges.size();i++){
            int temp = max(d1[i],d2[i]);
            if(mini>temp){
                mini=temp;
                result=i;
            }
        }
        return result;
    }
};