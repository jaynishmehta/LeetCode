class Solution {
public:
    string triangleType(vector<int>& n) {
        int s1=0,s2=0,s3=0;
        s1=n[0]+n[1];
        s2=n[1]+n[2];
        s3=n[2]+n[0];
        if((n[0]+n[1]>n[2])&& (s2>n[0]) && (s3>n[1])){
            if((n[0]==n[1]) &&(n[1]==n[2]))return "equilateral";
            else if((n[0]==n[1])||(n[1]==n[2])||(n[2]==n[0]))return "isosceles";
            
            else return "scalene";
        }
        else return "none";
    }
};