class Solution {
public:
    bool check(string w, string p){
        for(int i=0;i<p.size();i++){
            if(w[i]!=p[i])return false;
        }
        return true;
    }
    int prefixCount(vector<string>& w, string p) {
        int cnt=0;
        for(int i=0;i<w.size();i++){
            cnt+= check(w[i],p);
        }
        return cnt;
    }
    
};