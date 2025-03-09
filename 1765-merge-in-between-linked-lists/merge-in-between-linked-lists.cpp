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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp =list1;
        int count=0;
        ListNode* newStart = NULL;
        ListNode* newEnd = NULL;
        while(temp!=NULL){
            if(count==a-1){
                newStart = temp;
            }
            if(count==b){
                newEnd = temp->next;
                break;
            }
            temp =temp->next;
            count++;
        }
        newStart->next = list2;
        ListNode* temp2 = list2;
        while(temp2->next != NULL){
            temp2=temp2->next;
        }
        temp2->next = newEnd;

        return list1;
    }
};