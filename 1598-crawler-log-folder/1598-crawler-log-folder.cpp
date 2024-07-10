class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        for(auto &it:logs){
            if(it=="./"){
                ans+=0;
            }
            else if(it=="../"&&ans!=0){
                ans-=1;
            }
            else if(it=="../"&&ans==0){
                ans+=0;
            }
            else{
                ans+=1;
            }
        }
       
        return ans;
    }
};