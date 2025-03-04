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
    bool hasCycle(ListNode *head) {
        
        if(head == nullptr || head->next == nullptr){
            return false;
        }
        //try using slow and faster pointer if circulr then they sholud collide at same point 
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow!=fast){
            if(fast->next == nullptr || fast->next->next==nullptr){
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;



        
        
    }
};