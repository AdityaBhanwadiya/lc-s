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

 // 1 2 3 4 3 2 1
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)  return head;

        ListNode* newHead = reverseList(head->next);

        ListNode* front = head ->next;
        front->next = head;
        head->next = nullptr;
        front = head;


        return newHead;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Slow is at the middle of the ll and fast at the end
        // reverse that second half only

        ListNode* newHead = reverseList(slow);

        while(newHead != NULL){
            if(head->val != newHead->val)
                return false;
            head = head->next;
            newHead = newHead->next;
        }
        return true;
        
    }
};