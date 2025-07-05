class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        int maxi=-1;
        for(auto it:m){
            if(it.second==it.first){
                maxi= max(maxi,it.second);
            }
        }
        return maxi;
    }
};