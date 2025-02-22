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
    int sizeLL(ListNode* head){
        ListNode* temp = head;
        int count =0;
        while(temp){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = sizeLL(head);
        //edge case
        if (n == size) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        int count =0;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp){
            count++;
            if(count==size-n+1){
                prev->next = temp->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
        
    }
};