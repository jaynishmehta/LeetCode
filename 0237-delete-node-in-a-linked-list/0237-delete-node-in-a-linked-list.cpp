/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //remove next element from the node and make sure the node.value = next node.value;
        node->val = node->next->val;
        node->next=node->next->next;
    }
};