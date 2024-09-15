class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto it:nums)pq.push(it);
        int prev=0;
        for(int i=0;i<k;i++){
            prev= pq.top();
            pq.pop();
        }
        return prev;
    }
};