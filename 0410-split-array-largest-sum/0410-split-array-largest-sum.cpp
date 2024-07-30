class Solution {
    bool possible(vector<int>& arr, int m,int mid){
  
    int count = 1;
    long long int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (sum + arr[i] <= mid)
        {
            sum += arr[i];
        }
        else
        {
            count++;
            if (count > m || arr[i] > mid)
            {
                return false;
            }
            sum = arr[i];
        }
    }
    return true;
}
public:
    int splitArray(vector<int>& nums, int k) {
        long long ans=1;
        long long l=0;
        long long h= 1e9;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(possible(nums,k,mid)){
                ans= mid;
                h= mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};