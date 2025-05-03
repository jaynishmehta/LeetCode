class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int>v1(7,0);
        vector<int>v2(7,0);
        int maxi1=0,maxi2=0;
        int m1=0,m2=0;
        for(int i=0;i<tops.size();i++){
            v1[tops[i]]++;
            if(maxi1<v1[tops[i]]){
                maxi1=v1[tops[i]];
                m1=tops[i];
            }
        }
        for(int i=0;i<bottoms.size();i++){
            v2[bottoms[i]]++;
            if(maxi2<v2[bottoms[i]]){
                maxi2=v2[bottoms[i]];
                m2=bottoms[i];
            }
        }
        cout<<m1<<" "<<m2;
        int cnt=0,ans=0;
        bool temp1=true,temp2=true;
        for(int i=0;i<tops.size();i++){
            if(tops[i]!=m1 && bottoms[i]==m1){
                cnt++;
            }
            else if(tops[i]!=m1 && bottoms[i]!=m1){
                temp1=false;
                break;
            }
        }
        ans= cnt;
        cnt=0;
        for(int i=0;i<bottoms.size();i++){
            if(bottoms[i]!=m2 && tops[i]==m2){
                cnt++;
            }
            else if(bottoms[i]!=m2 && tops[i]!=m2){
                temp2=false;
                break;
            }
        }
        if(temp1==false && temp2==false)return -1;
        if(temp1==false && temp2==true)return cnt;
        if(temp1==true && temp2==false)return ans;
        else return min(ans,cnt);
    }
};