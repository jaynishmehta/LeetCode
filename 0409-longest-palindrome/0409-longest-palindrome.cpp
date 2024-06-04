class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>m;
        for(auto it:s){
            m[it]++;
        }
        int even=0;
        int odd=0;
        vector<int>v;
        int odd_maxi=0;
        for(auto it:m){
            if(it.second%2==0)even+=it.second;
            else{
                v.push_back(it.second);
            }
        }
        if(v.size()>0){
            sort(v.begin(),v.end(),greater<int>());
            odd+=v[0];
            for(int i=1;i<v.size();i++){
                if(v[i]>1){
                    odd+=(v[i]-1);
                }
            }
        }
        return odd+even;
    }
};