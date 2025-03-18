class Solution {
public:
    bool findbits(int i,int j,vector<int>&nums,vector<int>&v){
        long long int x= nums[j];
        int k=0;
        while(x!=0){
            if(((x&1)==1) && (v[k]!=1)){
                v[k]=1;
                k++;
                x=x>>1;
            }
            else if(((x&1)==1) && v[k]==1){
                return false;
            }
            else{
                x=x>>1;
                k++;
            }

        }
        return true;
    }
    int longestNiceSubarray(vector<int>& nums) {
        vector<int>v(31,0);
        int i=0,j=0;
        int maxi=0;
        while(j<nums.size()){
            if(findbits(i,j,nums,v)==true){
                maxi= max(maxi,j-i+1);
                // cout<<i<<"i&j "<<j<<endl;
                j++;
            }
            else if(findbits(i,j,nums,v)==false){
                // v={0};
                // cout<<v[0]<< v[1]<<endl;
                fill(v.begin(), v.end(), 0);
                i++;
                j=i;
            }
        }
        return maxi;
    }
};