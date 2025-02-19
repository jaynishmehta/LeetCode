class Solution {
public:
    void solve(int index,string temp,vector<char>&val,vector<string>&v,int n){
        // string temp += val[(i+3)%3];
        if(index==n){
            v.push_back(temp);
            return;
        }
        for (char c : val) {
            if (temp.empty() || temp.back() != c) { // Avoid consecutive same characters
                solve(index + 1, temp + c, val, v, n);
            }
        }

    }
    string getHappyString(int n, int k) {
        int pos= 3*(pow(2,n-1));
        if(pos<k)return "";
        vector<string>v;
        vector<char>val={'a','b','c'};
        // string temp="";
        solve(0,"",val,v,n);
        
        // sort(v.begin(),v.end());
        cout<<v[0]<<v[1];
        return v[k-1];
    }
};