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
    bool isPalindrome(ListNode* head) {
        ListNode* start = head;
        ListNode* tail = head;
        stack<int> st;

        while(tail->next != NULL) {
            st.push(tail->val);
            tail = tail->next;
        }
        st.push(tail->val);

        // 1 2 2 1

        while(!st.empty()) {
            if(start->val == st.top()){
                start = start->next;
                st.pop();
            }else{
                return false;
            }
        }

        return true;

    }
};