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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL)  return nullptr;
        int len = 0;

        ListNode* temp = head;

        while(temp != NULL){
            temp = temp->next;
            len++;
        }

        int fromFront = len - n;
        if (fromFront == 0) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
            return head;
        }


        temp = head;

        int count = 0;
        while(count != fromFront-1){
            temp = temp->next;
            count++;
        }

        ListNode* toDelete = temp->next;

        temp->next = toDelete->next;
        toDelete->next = NULL;

        return head;
    }
};