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
    int count=0;
    ListNode* temp = head;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;

}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1) return head;
        int size = sizeLL(head);
        int group = size/k;
        ListNode* nhead = new ListNode(0);
        nhead->next= head;
        ListNode* prevGroupEnd = nhead;

        while(group--){
            ListNode* curr = prevGroupEnd->next;
            ListNode* nextGroupStart = curr;
            ListNode* temp = nullptr;
            ListNode* prev = nullptr;

            for(int i=0;i<k;i++){
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            } 
            nextGroupStart->next = curr;
            prevGroupEnd->next = prev;
            prevGroupEnd = nextGroupStart;
        }

        return nhead->next;
    }
};