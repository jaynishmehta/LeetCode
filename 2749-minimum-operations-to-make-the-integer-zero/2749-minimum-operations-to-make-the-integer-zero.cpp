class Solution {
public:
    int cnt_bits(long long int t){
        int cnt=0;
        while(t){
            if(t&1){
                cnt++;
            }
            t=t>>1;
        }
        return cnt;
    }

    int makeTheIntegerZero(int num1, int num2) {
        if(num2>=num1)return -1;
        long long int cnt=1;
        long long int t= num1-num2;
        while(true){
            if(t<=0)return -1;
            if(cnt_bits(t)<=cnt){
                if(cnt_bits(t) <= cnt && cnt <= t)return cnt;
                return -1;
                break;
            }
            else{
                t= t-num2;
                cnt++;
            }
        }
        return -1;
    }
};