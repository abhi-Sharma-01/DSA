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
            temp= temp->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size  = sizeLL(head);
        if( size == n){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode* temp = head;
        int count =0;
        while(temp!=NULL){
            count++;
            if(count == size-n){
                break;
            }
            temp= temp->next;
        }
        ListNode* todelete = temp->next;
        temp->next = temp->next->next;
        delete todelete;
        return head;
        
    }
};