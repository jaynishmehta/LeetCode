class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int temp= maxWeight/w ;
        if(temp>n*n)return n*n;
        else return temp;
    }
};