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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB==NULL){
            return NULL;
        }
        ListNode* temp = NULL;
        map<ListNode*, int> mapp;
        temp = headA;
        while(temp!=NULL){
            mapp[temp] = 1;
            temp= temp->next;
        }
        temp = headB;
        while(temp!=NULL){
            if(mapp[temp]==1){
                return temp;
            }
            temp= temp->next;
        }
        return NULL;

    }
};