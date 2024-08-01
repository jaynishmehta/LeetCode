class Solution {
    int cnt=0;
public:
    int countSeniors(vector<string>& d) {
        for(auto it:d){
            int a= int(it[11])-48;
            cout<<a<<" ";
            int b= a*10 + (int(it[12])-48);
            if(b>60)cnt++;
            cout<<b<<" "<<endl;
        }
        return cnt;
    }
};