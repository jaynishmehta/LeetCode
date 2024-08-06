class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>m;
        // set<char>s;
        for(auto it:word){
            m[it]++;
            // s.insert(it);
        }
        // map<int,char>m1;
        vector<int>v;
        for(auto it:m){
            // m1[it.second]=it.first;
            v.push_back(it.second);
        }
        sort(v.begin(),v.end());
        
        long long int cnt=1;
        long long int ans=0;
        for(int i=v.size()-1;i>=0;i--){
            if(cnt<=8){
                // cout<<
                ans+=(1*v[i]);
            }
            else if(cnt>8 && cnt<=16){
                ans+=(2*v[i]);
            }
            else if(cnt>16 && cnt<=24){
                ans+=(3*v[i]);
            }
            else{
                ans+=(4*v[i]);
            }
            cnt++;
        }
        return ans;
    }
};