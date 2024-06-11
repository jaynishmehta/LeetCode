class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>m;
        for(auto it:arr1){
            m[it]++;
        }
        vector<int>v;
        map<int,int>m2;
        for(int i=0;i<arr2.size();i++){
            m2[arr2[i]]++;
            if(m.find(arr2[i])!=m.end()){
                while(m[arr2[i]]--){
                    v.push_back(arr2[i]);
                }
            }
            
           
        }
        vector<int>left;
        for(int i=0;i<arr1.size();i++){
            if(m2.find(arr1[i])==m2.end())
                left.push_back(arr1[i]);
        }
        sort(left.begin(),left.end());
        for(auto it:left){
            v.push_back(it);
        }
        return v;
    }
};