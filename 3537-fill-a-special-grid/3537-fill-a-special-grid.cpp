class Solution {
public:
    int val=0;
    void solve(int r,int c,int size,vector<vector<int>>&ans){
        if(size==1){
            ans[r][c]=val++;
            return ;
        }
        int sub_s= size/2;
        solve(r,c+sub_s,sub_s,ans); //top-right
        solve(r+sub_s,c+sub_s,sub_s,ans); //botto.-right;
        solve(r+sub_s,c,sub_s,ans); //bottom-left
        solve(r,c,sub_s,ans); //top-left
    }

    vector<vector<int>> specialGrid(int N) {
        int n=1<<N;
        vector<vector<int>>ans(n,vector<int>(n,0));
        solve(0,0,n,ans);
        return ans;
    }
};