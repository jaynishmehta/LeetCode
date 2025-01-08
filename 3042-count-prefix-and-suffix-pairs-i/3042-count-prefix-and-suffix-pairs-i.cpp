class Solution {
    bool checkpairs(string a,string b){
        string c= b;
        string d=a;
        reverse(d.begin(),d.end());
        reverse(c.begin(),c.end());
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i] || d[i]!=c[i])return false;
        }
        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt=0;
        for(int i=0;i<words.size()-1;i++){
           for(int j=i+1;j<words.size();j++){
             if(checkpairs(words[i],words[j]))cnt++;
           }
        }
        return cnt;
    }
};