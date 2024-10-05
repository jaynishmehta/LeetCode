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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* lh1 = list1;
        ListNode* lh2 = list2;

        // Create a dummy node to avoid edge cases of handling first node
        ListNode* dummy = new ListNode(-1); // Use a dummy node
        ListNode* current = dummy; 
        while (lh1 != nullptr && lh2 != nullptr) {
            if (lh1->val < lh2->val) {
                current->next = lh1;
                lh1 = lh1->next;
            } else {
                current->next = lh2;
                lh2 = lh2->next;
            }
            current = current->next;
        }

        // If one list has remaining elements, attach it
        if (lh1 != nullptr) {
            current->next = lh1;
        } else if (lh2 != nullptr) {
            current->next = lh2;
        }

        // Return the merged list, skipping the dummy node
        return dummy->next;
    }
};