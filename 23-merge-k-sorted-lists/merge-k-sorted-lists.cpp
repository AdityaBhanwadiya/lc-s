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
    struct CompareNodes {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; 
        }
};
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNodes> minHeap;

        for(auto it : lists) {
            ListNode* curr = it;
            while (curr != nullptr) {
                minHeap.push(curr);
                curr = curr->next;
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();

            tail->next = node;
            tail = tail->next;
        }

        tail->next = nullptr;

        return dummy->next;
    }
};