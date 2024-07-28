class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>v(10000,-1);
        for(int i=0;i<arr.size();i++){
            v[arr[i]]=1;
        }
        int cnt=0;
        for(int i=1;i<=v.size();i++){
            if(v[i]==-1)cnt++;
            if(cnt==k){
                return i;
            }
        }
        return 0;
    }
};