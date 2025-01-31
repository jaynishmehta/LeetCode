class Solution {
public:
    int getSum(int a, int b) {
        //eg 14+7;
        int carry= a&b;
        int sum = a^b;
        // if(carry==0)return sum;
        while(carry!=0){
            int temp_carry= sum & (carry<<1); //(carry goes to next bit)
            sum = sum^(carry<<1);
            carry= temp_carry;
        }
        return sum;
    }
};