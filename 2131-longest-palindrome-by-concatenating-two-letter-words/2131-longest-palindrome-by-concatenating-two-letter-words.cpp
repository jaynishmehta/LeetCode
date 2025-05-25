class Solution {
public:
    int longestPalindrome(vector<string>& w) {
        unordered_map<string,int>m;
        for(auto it:w)m[it]++;
        int mid=0;
        string mid_s;
        unordered_map<string,int>m1;
        for(auto it:m){
            string s=it.first;
            m1[s]=-1;
            cout<<s<<" "<<it.second<< endl;
        }

        int ans=0;
        unordered_map<string,int>same;

        for(auto it:m){
            string s = it.first;
            string s1=s;
            reverse(s1.begin(),s1.end());
            
            if(s[0]==s[1] && (m1[s]==-1)){
                
                if(m[s]*2 > mid && (m[s]%2==1)){
                    mid_s=s;
                    mid= m[s]*2;
                }
                // else{
                //     mid= max(m[s]*2,mid);
                // }
                m1[s]=1;
                same[s]=m[s];
                // cout<<s[0]<<" "<<s[1]<<mid<<endl;
            }
            else if((m.find(s1)!=m.end()) && (m1[s]==-1 && m1[s1]==-1)){
                // cout<<s1<<" "<<s<<endl;
                int temp = min(m[s1],m[s]);
                ans+=(4*temp);
                m1[s]=1;
                m1[s1]=1;
                // cout<<temp<<" "<<m[s1]<<" "<<m[s]<<ans<< endl;
            }
        }
        for(auto it:same){
            if(it.first==mid_s){
                ans+=mid;
            }
            else{
                int temp = it.second/2;
                ans+= (temp*4);
            }
        }
        // ans+=mid;
        return ans;
    }
};