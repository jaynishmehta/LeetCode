class Solution {
public:
    int digitsum(int n){
        int temp=0;
        while(n){
            temp += n%10;
            n=n/10;
        }
        return temp;
    }
    int minSwaps(vector<int>& n) {
        // vector<int>n=nums;
        vector<pair<int,int>>v;
        unordered_map<int,int>m;

        for(int i=0;i<n.size();i++){
            v.push_back({digitsum(n[i]),n[i]});
        }

        sort(v.begin(),v.end());
        // for(auto it:v){
        //     cout<<it.second<<"->" << it.first<<" ";
        // }

        for(int i=0;i<v.size();i++){
            m[v[i].second]=i;
        }
        
        //changing the n vector to v;

    int swaps=0;
       for(int i=0;i<n.size();i++){
            int temp = n[i];
            int pos= m[temp];
            if(i!=pos){
                m[temp]=i;
                m[v[i].second]=pos;
                swap(v[i],v[pos]);
                swaps++;
            }
        }
        // for(int i=0;i<n.size();i++){
        //     int temp=v[i].second;
        //     int pos= m[temp];
        //     if(pos!=i){
        //         swap(v[i],v[pos]);
        //         swaps++;
        //     }
        // }
        
        return swaps;
    }
};