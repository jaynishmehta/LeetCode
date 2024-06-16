class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<long long,long long>freq;
        // freq[0]=1;
        long long cnt=0;
        for(int i=0;i<hours.size();i++){
            long long rem= hours[i]%24;
            if(rem==0){
                cnt+=freq[0];
            }
            else{
                cnt+=freq[24-rem];
            }
            freq[rem]++;
        }
        return cnt;
    }
};