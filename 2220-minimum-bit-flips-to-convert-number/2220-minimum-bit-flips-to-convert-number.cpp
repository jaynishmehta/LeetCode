class Solution {
public:
    int minBitFlips(int start, int goal) {
    int c= start^goal;
    int count=0;
    while(c!=0){
        if((c&1)!=0){
            count++;
        }
        c=c>>1;
    }
    return count;
    }
};