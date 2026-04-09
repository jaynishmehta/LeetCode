class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto it:nums){
            m[it]++;
        }
        map<int,vector<int>>mm;
        for(auto it:m){
            mm[it.second].push_back(it.first);
        }
        // mm = {
        // 1 : [3],
        // 2 : [1,2]
        // }
        //times- ele
        vector<int>v;
        for(auto it:mm){
            
            vector<int>y=it.second;
            sort(y.begin(),y.end(),greater<int>());
            for(int i=0;i<y.size();i++){
                int x= it.first;
                while(x>0){
                        v.push_back(y[i]);
                        x--;
                        
                    
                    }
            }
        }
        return v;

    }
};