class Solution {
public:
    int count_bits(int x){
        int cnt=0;
        while(x!=0){
            if(x&1==1)cnt++;
            x=x>>1;
        }
        return cnt;
    }
    int countPrimeSetBits(int left, int right) {
        unordered_map<int,int>prime;
        int cnt=0;
        prime[2]++;
        prime[3]++,prime[19]++;
        prime[5]++ ,prime[7]++,prime[11]++,prime[13]++,prime[17]++;
        for(int i=left;i<right+1;i++){
            int x=count_bits(i);
            if(prime.find(x)!=prime.end()){
                cnt++;
            }
        }
        return cnt;
    }
};