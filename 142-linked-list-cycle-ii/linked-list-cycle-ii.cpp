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
    ListNode *detectCycle(ListNode *head) {
        if(head== NULL || head->next == NULL){
            return nullptr;
        }
        ListNode* temp = head;
        map<ListNode* , int> mapp;
        int count = 1;
        while(temp!= nullptr){
            if(mapp[temp]!=0  ){
                return temp;
            }
            mapp[temp] = count;
            count++;
            temp = temp->next;
        }
        return nullptr;        
    }
};