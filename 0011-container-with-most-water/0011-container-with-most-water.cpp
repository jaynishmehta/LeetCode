class Solution {
public:
    int maxArea(vector<int>& h) {
        int i=0,j=h.size()-1;
        int maxi=INT_MIN;
        while(i<j){
            
            int l=min(h[i],h[j]);
            maxi = max(maxi,l*(j-i));
            if(h[i]>h[j])j--;
            else i++;
        }
        return maxi;
    }
};