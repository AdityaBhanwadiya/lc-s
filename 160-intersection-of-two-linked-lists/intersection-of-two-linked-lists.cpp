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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> myMap;

        ListNode* temp = headA;
        while(temp != NULL) {
            myMap[temp] = temp->val;
            temp=temp->next;
        }

        temp = headB;

        while(temp!= NULL){
            if(myMap.find(temp) != myMap.end()){
                return temp;
            }
            temp=temp->next;
        }
        return nullptr;
    }
};