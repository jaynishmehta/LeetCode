class Solution {
public:
    int cntbits(int n){
        int cnt=0;
        while(n!=0){
            if((n&1)==1)cnt++;
            n=n>>1;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        map<int,priority_queue<int,vector<int>,greater<int>>>m;
        // map<int,vector<int>>m;

        for(int i=0;i<arr.size();i++){
            int x= cntbits(arr[i]);
            m[x].push(arr[i]);
        }
        vector<int>v;
        for(auto it:m){
            while(!it.second.empty()){
                v.push_back(it.second.top());
                it.second.pop();
            }
            // sort(it.second.begin(),it.second.end());
            // for(auto its:it.second){
            //     v.push_back(its);
            // }
        }
        return v;
    }
};