/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode *temp=head;
        vector<int>v;
        while(temp!=NULL ){
            v.push_back(temp->val);
            temp= temp->next;
        }
        int ans=0;
        int j=0;
        for(int i=v.size()-1;i>=0;i--){
            ans+= (pow(2,j))*v[i];
            j++;
        }
        return ans;
    }
};