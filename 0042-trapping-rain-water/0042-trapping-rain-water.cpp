class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        vector<int>leftmaxi(n);
        vector<int>rightmaxi(n);
        int maxi=0;
        for(int i=0;i<n;i++){
            leftmaxi[i]=max(maxi,static_cast<int>(height[i]));
            maxi=leftmaxi[i];
        }
        maxi=0;
        for(int i=n-1;i>=0;i--){
            rightmaxi[i]=max(maxi,static_cast<int>(height[i]));
            maxi=rightmaxi[i];
        }
        long long area=0;
        for(int i=0;i<n;i++){
            area+= (min(rightmaxi[i],leftmaxi[i])- height[i]);
        }
        return area;
    }
};