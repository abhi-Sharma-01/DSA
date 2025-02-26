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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr; // If the list is empty or has only one node, return nullptr
        }
        ListNode* Slow = head;
        ListNode* Fast = head;
        ListNode* prev = nullptr;
        while(Fast != NULL && Fast->next != NULL){
            prev = Slow;
            Slow = Slow->next;
            Fast = Fast->next->next;
        }
        prev->next = Slow->next;
        delete Slow;
    
        /* As now Slow is at middle Node we can stop
         and implement deletion on the node  */
        // ListNode* temp = Slow->next;
        // Slow->val = Slow->next->val;  //This can be the way but fails if size = 2
        // Slow->next = Slow->next->next;
        // delete temp;

        return head;

    }
};