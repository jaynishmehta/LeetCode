class Solution {
public:
    vector<int> findWordsContaining(vector<string>& w, char x) {
        int cnt=0;
        vector<int>v;
        for(int i=0;i<w.size();i++){
            // int t = w[i].find(x);
            // if(t!= string::npos){
            //     v.push_back(i);
            // }
            if(w[i].find(x)!=-1){
                v.push_back(i);
            };
        }
        return v;
    }
};