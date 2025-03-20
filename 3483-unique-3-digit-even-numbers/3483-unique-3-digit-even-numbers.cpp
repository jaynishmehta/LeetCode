class Solution {
public:
    int totalNumbers(vector<int>& d) {
        int ans=0;
        map<int,int>m;
        for(auto it:d){
            m[it]++;
            
        }
        
        for(int i=100;i<999;i+=2){
            int j=i;
                int a= j%10;
                j=j/10;
                int b= j%10;
                j=j/10;
                int c= j%10;
                vector<int>v(10,0);
                v[a]++;
                v[b]++;
                v[c]++;
                if(m[a]>=v[a] && m[b]>=v[b] && m[c]>=v[c]){
                    ans++;
                }
        }
        
        return ans;
    }
};