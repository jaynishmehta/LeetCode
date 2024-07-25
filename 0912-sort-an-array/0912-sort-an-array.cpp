class Solution {
    void merge(vector<int>& arr,int l,int mid,int r){
        vector<int>v;
        int i=l;
        int j= mid+1;
        
        while(i<=mid && j<=r){
            if(arr[i]<=arr[j]){
                v.push_back(arr[i]);
                i++;
            }
            else{
                v.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid){
            v.push_back(arr[i]);
            i++;
        }
        while(j<=r){
            v.push_back(arr[j]);
            j++;
        }
        
        for(int w=l;w<=r;w++){
            arr[w]=v[w-l];
        }
    }
    
    void mergesort(vector<int>& n,int l,int r){
        if(l==r)return;
        int mid= (l+r)/2;
        mergesort(n,l,mid);
        mergesort(n,mid+1,r);
        merge(n,l,mid,r);
        }
public:
    vector<int> sortArray(vector<int>& n) {
        mergesort(n,0,n.size()-1);
        return n;
    }
};