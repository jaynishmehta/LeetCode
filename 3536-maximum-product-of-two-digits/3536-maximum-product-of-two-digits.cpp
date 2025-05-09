class Solution {
public:
    int maxProduct(int n) {
       vector<int> v;
       while(n>0){
        int t =  n%10;
        n=n/10;
        v.push_back(t);
       }
       sort(v.begin(),v.end(),greater());
       return v[0]*v[1];
    }
};