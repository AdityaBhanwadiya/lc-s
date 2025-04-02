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
    // 9 9 9 9 9 9 9
    // 9 9 9 9
    // 8 9 9 9 0 0 0 1
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int carry = 0;

        while(temp1 != NULL || temp2!= NULL || carry) {
            int val1 = temp1 ? temp1->val : 0;
            int val2 = temp2 ? temp2->val : 0;
            int sum = val1 + val2 + carry;

            ListNode* newNode = new ListNode(sum%10);
            temp->next = newNode;
            temp = temp->next;
            carry = sum/10;

            if(temp1)   temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
        }

        // if(temp1 != NULL){
        //     while(temp1 != NULL) {
        //         int sum = temp2->val + carry;
        //         ListNode* newNode = new ListNode(sum%10);
        //         temp->next = newNode;
        //         carry = sum/10;

        //         temp1 = temp1->next;
        //     }
        // }else{
        //     while(temp2 != NULL) {
        //         int sum = temp1->val + carry;
        //         ListNode* newNode = new ListNode(sum%10);
        //         temp->next = newNode;
        //         int carry = sum/10;

        //         temp2 = temp2->next;
        //     }
        // }

        // if(carry){
        //     ListNode* carryNode = new ListNode(1);
        //     temp->next = carryNode;
        // }
        
        return dummy->next;
    }
};