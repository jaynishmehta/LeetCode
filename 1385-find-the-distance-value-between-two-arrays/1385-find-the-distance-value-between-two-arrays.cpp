class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt=0;
        for(int i =0;i<arr1.size();i++){
            bool temp=true;
            for(auto it:arr2){
                if(abs(arr1[i]-it)<=d){
                    temp=false;
                    // cnt = min(cnt,abs(arr1[i]-it));
                }
            }
            if(temp)cnt++;
        }
        return cnt;
    }
};