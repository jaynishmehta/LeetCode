class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long int s1=0,s2=0;
        int c1=0,c2=0;
        for(auto it:nums1){
            s1+=it;
            if(it==0)c1++;
        }
        for(auto it:nums2){
            s2+=it;
            if(it==0)c2++;
        }
        cout<<s1 << " "<<s2;
        if((s1+c1<= s2+c2) ){
            for(int i=0;i<nums2.size();i++){
                if(nums2[i]==0){
                    nums2[i]=1;
                    s2++;
                }
            }
            int diff= s2-s1;
            if(diff<c1 && c1==0)return -1;
            if(s2>s1 && c1==0) return -1;
            return s2;

        }
        else{
            for(int i=0;i<nums1.size();i++){
                if(nums1[i]==0){
                    nums1[i]=1;
                    s1++;
                }
            }
            int diff= s1-s2;
            if(diff<c2 && c2==0)return -1;
            if(s2<s1 && c2==0) return -1;
            return s1;
        }
        return min(s1,s2);
    }
};