class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {  
            int carry = (a & b);  // Carry bits
            a = a ^ b;  // Sum without carry
            b = (carry) << 1;  // Move carry to next position
        }
        return a;  
    }
};



// class Solution {
// public:
//     int getSum(int a, int b) {
//         int c=0;
//         int ans=0;
//         int i=0;
//         if(a>0 && b>0){
//             c=0;
//             while(a>0 || b>0){
//                 // if((a&1) & (b&1)){
//                     int temp= (a&1)+(b&1)+(c&1);
//                     ans+= (temp &1)*pow(2,i);
//                     temp=temp>>1;
//                     c=temp;
//                 // }
//                 // else if((a&1==0) && (b&1==0)){
//                 // }
//                 i++;
//                 a=a>>1;
//                 b=b>>1;
//             }
//             if(c){
//                 ans+= c*(pow(2,i));
//             }
//         }
//         else if((a>0 && b<=0)&& (abs(a)>abs(b))){
//             c=0;
//             b*=-1;
//             // cout<<b;
//             while(a>0){
//                 if((a&1==0) && (b&1==1)){
//                     if(c==0){
//                         c=1;
//                         ans+= (1*pow(2,i));
//                     }
//                     else{
//                         c=0;
//                         ans+=(0*pow(2,i));
//                     }
//                     i++;
//                     a=a>>1;
//                     b=b>>1;
//                 }
//                 else if((a&1==0)&&(b&1==0)){
//                     if(c==1){
//                         c=0;
//                         ans+= (1*pow(2,i));
//                     }
//                     else{
//                         c=0;
//                         ans+=(0*pow(2,i));
//                     }
//                     i++;
//                     a=a>>1;
//                     b=b>>1;
//                 }
//                 else if((a&1==1)&&(b&1==1)){
//                     if(c==1){
//                         c=1;
//                         ans+= (1*pow(2,i));
//                     }
//                     else{
//                         c=0;
//                         ans+=(0*pow(2,i));
//                     }
//                     i++;
//                     a=a>>1;
//                     b=b>>1;
//                 }
//                 else if((a&1==1)&&(b&1==0)){
//                     if(c==1){
//                         c=0;
//                         ans+= (0*pow(2,i));
//                     }
//                     else{
//                         c=0;
//                         ans+=(1*pow(2,i));
//                     }
//                     i++;
//                     a=a>>1;
//                     b=b>>1;
//                 }
//             }
//         }
//         return ans;
//     }
// };