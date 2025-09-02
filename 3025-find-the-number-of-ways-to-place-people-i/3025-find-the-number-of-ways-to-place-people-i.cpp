class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
        // sort(p.begin(),p.end());
        int cnt=0;
        for(int i=0;i<p.size();i++){

            for(int j=0;j<p.size();j++){
                if (i == j || p[j][0] < p[i][0] || p[j][1] > p[i][1]) {
                    continue; 
                }
                bool temp=false;
                for(int k=0;k<p.size();k++){
                    if(i==k || j==k)continue;
                    if((p[i][0]<= p[k][0] && p[k][0]<=p[j][0]) && (p[i][1]>=p[k][1])&&(p[k][1]>=p[j][1])){
                        temp=true;
                        break;
                    }
                    
                }
                if(temp==false)cnt++;
            }
        }
        return cnt;
        // jaynish_mehta,, 
    }
};