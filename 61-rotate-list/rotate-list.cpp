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
    
    
    ListNode* rotateRight(ListNode* head, int k) {
        // Method1 :
        // brute force for k time unlink last node and point to head;

        // Method2: 
        if(!head || head->next ==NULL || k==0) return head;
        ListNode* temp = head;
        int length =1;
        while(temp->next!=NULL){
            temp = temp->next;
            length++;
        }
        temp->next = head; // Making the loop cyclic by pointing the last node to the head
        k = k % length;
        int newHead = length - k;
        temp = head;
        for(int i=1;i<newHead;i++){
            temp = temp->next;
        }
        head = temp ->next;
        temp->next = nullptr;

        return head;      
    }
};