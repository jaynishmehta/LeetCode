// class Solution {
// public:

//     bool check(int n,vector<int>&v,int j,int k){
//         // unordered_map<int,int>m;
        
//         if(n==0)return true;
//         if(k>v.size())return false;
        
        
//         for(int i=j;i<k;i++){
//             if(n%10==v[i]){
//                 if(check(n/10,v,i+1,i+2))return true;
//             }
//         }
//         return false;
    
        
//     }
//     bool isprime(long long int n){
//         if(n==1)return  false;
//         for(int i=2;i*i<=n;i++){
//             if(n%i ==0){
//                 return false;
//             }
//         }
//         return true;
//     }

//     long long sumOfLargestPrimes(string s) {
//         vector<int>v;
//         int cnt=0;
//         for(auto it:s){
//             // v[it-'0']++;
//             v.push_back(it-'0');
//         }
//         reverse(v.begin(),v.end());
//         // vector<string> substrings;
//         set<long long int>ss;

//         for (int i = 0; i < s.size(); ++i) {
//             string current = "";
//             for (int j = i; j < s.size(); ++j) {
//                 current += s[j];
//                 // substrings.push_back(current);
//                 ss.insert(stoll(current));
//             }
//         }

//         int z= stoi(s);
//         priority_queue<long long int>pq;
//         for(auto it:ss){
//             if(check(it,v,0,v.size()) && isprime(it)){
//                 cout<<it<<" ";
//                 // cnt+=i;
//                 pq.push(it);
//             }
//         }
//         int k=0;
//         while(!pq.empty() && k<3){
//             cnt+=pq.top();
//             pq.pop();
//             k++;
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    bool check(long long n, const vector<int>& v, int j, int k) {
        if (n == 0) return true;
        if (k > v.size()) return false;

        for (int i = j; i < k; i++) {
            if (n % 10 == v[i]) {
                if (check(n / 10, v, i + 1, i + 2)) return true;
            }
        }
        return false;
    }

    bool isPrime(long long n) {
        if (n < 2) return false;
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    long long sumOfLargestPrimes(string s) {
        vector<int> v;
        for (char ch : s) {
            v.push_back(ch - '0');
        }
        reverse(v.begin(), v.end());

        set<long long> substrNums;
        for (int i = 0; i < s.size(); ++i) {
            string current = "";
            for (int j = i; j < s.size(); ++j) {
                current += s[j];
                try {
                    long long num = stoll(current);
                    substrNums.insert(num);
                } catch (const out_of_range&) {
                    continue;
                }
            }
        }

        vector<long long> primes;
        for (auto num : substrNums) {
            if (check(num, v, 0, v.size()) && isPrime(num)) {
                primes.push_back(num);
            }
        }

        sort(primes.rbegin(), primes.rend());
        long long result = 0;
        for (int i = 0; i < min(3, (int)primes.size()); ++i) {
            result += primes[i];
        }
        return result;
    }
};
