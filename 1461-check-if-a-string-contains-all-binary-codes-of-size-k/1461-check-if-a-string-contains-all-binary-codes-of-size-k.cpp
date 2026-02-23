class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string>ss;
        int n1= s.size();
        for(int i = 0; i <= n1 - k; i++) {
            ss.insert(s.substr(i, k));
        }
       
        int n= ss.size();
        for(auto it:ss)cout<<it<<" ";
        if(n==pow(2,k))return true;
        else return false;
    }
};