// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         vector<long  long >v;
//         long long double sum=0;
//         map<long long double ,int>m;
//         for(int i=0;i<nums1.size();i++){
//             v.push_back(nums1[i]);
//             sum+=nums1[i];
//             m[nums1[i]]++;
//         }
//         for(auto it:nums2){
//             v.push_back(it);
//             sum+=it;
//             m[it]++;
//         }
//         // sort(v.begin(),v.end());
//         sum/=double((nums1.size()+nums2.size()));
//         double ans=0;
//         int maxi=0;
//         long long double max_dig=INT_MIN;
//         for(auto it:m){
//             if(it.second>maxi){
//                 maxi=it.second;
//                 max_dig=it.first;
//             }
//         }
//         ans= (max_dig+2*sum)/double(3);
        
        
//     }
// };
#include <vector>
#include <iostream>
#include <iomanip> // Include iomanip for fixed and setprecision

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Ensure nums1 is the smaller array to minimize binary search steps
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int x = nums1.size();
        int y = nums2.size();
        int low = 0, high = x;

        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;

            int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];

            int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];

            if (maxX <= minY && maxY <= minX) {
                if ((x + y) % 2 == 0) {
                    return (double)(std::max(maxX, maxY) + std::min(minX, minY)) / 2;
                } else {
                    return (double)std::max(maxX, maxY);
                }
            } else if (maxX > minY) {
                high = partitionX - 1;
            } else {
                low = partitionX + 1;
            }
        }
        
        throw std::invalid_argument("Input arrays are not sorted");
    }
};

