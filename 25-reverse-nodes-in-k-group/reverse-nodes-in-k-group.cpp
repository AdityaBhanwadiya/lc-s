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
private:
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = NULL;        // nothing before the head
        ListNode* curr = head;        // start at head
        ListNode* next = NULL;        // placeholder

        while (curr != NULL) {
            next = curr->next;    // store next node
            curr->next = prev;    // reverse the link
            prev = curr;          // move prev forward
            curr = next;          // move curr forward
        }

        return prev;              // prev is the new head now
    }
    ListNode* findkthNode (ListNode* temp, int k) {
        k--;
        while(temp != NULL && k > 0) {
            temp = temp->next;
            k--;
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        ListNode* kthNode = NULL;
        
        while(temp != NULL){
            kthNode = findkthNode(temp, k);
            if(kthNode == NULL) {
                //todo
                if(prevNode)    prevNode->next = temp;
                break;
            }else{
                ListNode* nextnode = kthNode->next;
                kthNode->next = NULL;


                ListNode* newHead = reverseLinkedList(temp);

                if(temp == head) {
                    head = kthNode;
                }else{
                    prevNode->next = kthNode;
                }
                prevNode = temp;
                temp = nextnode;
            }
        }
        
        return head;
    }
};