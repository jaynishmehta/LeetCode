class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<double>s;
        for(auto it:arr){
            if((s.find(it*2)!=s.end())){
                cout<<it<<" "<<it *2;
                return true;
            }
            else if(s.find(double(it)/double(2))!=s.end()){
                return true;
            }
            else{
                s.insert(it);
            }
        }
        return false;
    }
};