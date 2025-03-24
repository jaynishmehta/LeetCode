class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {

        // vector<int>v(days,0);
        sort(m.begin(),m.end());
        int maxi=m[0][1];;
        // int prev= 
        int cnt=m[0][0]-1;
        for(int i=0;i<m.size();i++){
            if(m[i][0]>maxi){
                cnt+=(m[i][0]-maxi -1);
            }
            if(maxi<m[i][1])maxi= m[i][1];
        }
        cnt+= (days-max(m[m.size()-1][1],maxi));
        return cnt;
    }
};