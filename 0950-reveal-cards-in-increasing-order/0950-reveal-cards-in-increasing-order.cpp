class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end(),greater<int>()); //sort in reverse starts from the the largest element
        vector<int>v;
        v.push_back(deck[0]);
        for(int i=1;i<deck.size();i++){
            int x=v[v.size()-1];
            v.erase(v.begin()+v.size()-1);
            // v.push_back(x);
            v.insert(v.begin() + 0, x); 
            v.insert(v.begin() + 0, deck[i]); 
        }
        return v;
    }
};
 ////peeche wale ko hta kr aage krna h then new element add krnaa
