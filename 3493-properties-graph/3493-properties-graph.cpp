class Solution {
public:
    void dfs(int row,vector<int>&v,vector<vector<int>>&b){
        v[row]=1;
        for(auto it:b[row]){
            if(!v[it]){
                dfs(it,v,b);
            }
        }
    }
    int numberOfComponents(vector<vector<int>>& pr, int k) {
        vector<vector<int>>adj(pr.size());
        for(int i=0;i<pr.size()-1;i++){
            sort(pr[i].begin(),pr[i].end());
            for(int j=i+1;j<pr.size();j++){
                sort(pr[j].begin(),pr[j].end());
                int k1=0,l=0;
             
                unordered_map<int,int>mp;
                while(k1<pr[i].size() && l <pr[j].size()){
                    if(pr[i][k1]==pr[j][l]){
                        mp[pr[i][k1]]++;
                        k1++;
                        l++;
                    }
                    else if(pr[i][k1]>pr[j][l]){
                        l++;
                    }
                    else if(pr[i][k1]<pr[j][l]){
                        k1++;
                    }
                }
                if(mp.size()>=k){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
                
            }
        }

        int cnt=0;
        vector<int>v(pr.size(),0);
        for(int i=0;i<pr.size();i++){
            if(!v[i]){
                dfs(i,v,adj);
                cnt++;
            }
        }
        
        return cnt;
    }
};