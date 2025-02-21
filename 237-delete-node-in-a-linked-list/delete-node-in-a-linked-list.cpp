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
    void deleteNode(ListNode* node) {
        // // Approach-1;
        node->val = node->next->val;
        ListNode* temp = node->next;// note we need to store node->next in the temp so that we can free it later otherwise it will create error 
        node->next = node->next->next;
        delete temp;

        // Approach - 2
        // ListNode* temp = node->next;
        // node->val = node->next->val;
        // node->next = temp->next;
        // delete temp;
        
    }
};