class Solution {
public:
    vector<int> successfulPairs(vector<int>& sp, vector<int>& p, long long s) {
        int n= p.size()-1;
        vector<int>cnt;
        sort(p.begin(),p.end());
        for(int i=0;i<sp.size();i++){
            double x =(double)sp[i]/s;
            int l= 0;
            int r= n;
            int ind=n+1;
            while(l<=r){
                int mid= (l+r)/2;
                if(p[mid]*x>=1){
                    ind=mid;
                    r=mid-1;
                    
                }
                else{
                    l=mid+1;
                }
            }
            // cout<<x<<" "<<ind<<endl;
            cnt.push_back((n-ind+1));
            
        }
        return cnt;
    }
};