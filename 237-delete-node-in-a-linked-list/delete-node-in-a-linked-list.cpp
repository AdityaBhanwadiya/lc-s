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
        // 4 5 1 9 3 2 0 delete 1
        ListNode* after = node->next; // after = 9


        while(after->next != NULL){
            node->val = after->val; // 4 5 9 3 2 0 0
            node = node->next; // node = 2 
            after = after->next; // after = 0
        }
        node->val = after->val;
        node->next = NULL;

    }
};