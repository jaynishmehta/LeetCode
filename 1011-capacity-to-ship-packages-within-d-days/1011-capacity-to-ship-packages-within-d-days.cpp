class Solution {
    bool func(vector<int>& w, int day,int mid){
        long long temp=0;
        long long cnt=0;
        for(int i=0;i<w.size();i++){
            temp+=(w[i]);
            if(temp==mid){
                cnt++;
                temp=0;
            }
            else if(temp>mid && (temp-w[i]) <= mid){
                cnt++;
                temp=w[i];
            }
        }
        if(temp>0)cnt+=ceil(double(temp)/double(mid));
        if(cnt<=day)return true;
        else return false;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long ans=1;
        long long int l= *max_element(weights.begin(),weights.end());
        long long int h= 1e9;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(func(weights,days,mid)){
                cout<<ans<<" ";
                ans=mid;
                h= mid-1;
            }
            else{
                l= mid+1;
            }
        }
        return ans;
    }
};