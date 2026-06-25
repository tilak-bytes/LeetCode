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
    // min heap comparator — smaller val has higher priority
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0) return NULL;

        ListNode* head = NULL;
        ListNode* tail = NULL;

        // push head of each list into min heap
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for(int i = 0; i < k; i++)
            if(lists[i] != NULL) pq.push(lists[i]);

        while(!pq.empty()) {
            ListNode* top = pq.top(); pq.pop(); // get smallest node

            if(top->next) pq.push(top->next);   // push next node of extracted list

            // append to result list
            if(head == NULL) 
                head = tail = top;

            else { 
                tail->next = top; 
                tail = tail->next; 
            }
        }
        return head;
    }
};