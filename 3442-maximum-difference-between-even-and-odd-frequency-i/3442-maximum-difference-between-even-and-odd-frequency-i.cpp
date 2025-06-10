class Solution {
public:
    int maxDifference(string s) {
        int min_odd=INT_MAX,max_odd=0;
        int min_even=INT_MAX,max_even=0;
        unordered_map<char,int>m;
        for(auto it:s){
            m[it]++;
        }
        for(auto it:m){
            if(it.second%2==0){
                max_even=max(max_even, it.second);
                min_even=min(min_even,it.second);
            }
            else{
                max_odd= max(max_odd,it.second);
                min_odd= min(min_odd,it.second);
            }
        }
        // int m1=max_odd-min_even;
        // int m2= max_odd-max_even;
        // cout<<m1<<" "<<m2;
        int maxi= max((max_odd-min_even),(max_odd-max_even));

        return maxi;
    }
};