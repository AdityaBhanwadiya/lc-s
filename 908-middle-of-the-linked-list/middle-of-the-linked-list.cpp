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
    ListNode* middleNode(ListNode* head) {
        // int length = 0;
        // ListNode* temp = head;

        // while(temp != NULL){
        //     temp = temp->next;
        //     length++;
        // }

        // int middle = ceil (length/2);

        // int count = 0;
        // temp = head;

        // while(count != middle) {
        //     temp = temp->next;
        //     count++;
        // }

        // return temp;


        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};


