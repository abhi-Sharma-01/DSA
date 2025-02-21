class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL ) return head;
        //(Here we generally used  edge case)i.e
        // if(head->val == val) {
        //     ListNode* temp = head;
        //     head = head->next;
        //     delete temp;
        // }
        // But by little modifying adding while loop we can automate check condition in loop

        // Now Handle the case where head nodes have the value to be removed
        while (head !=NULL && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            if (temp->val == val) {
                if (prev != NULL) {
                    prev->next = temp->next;
                }
                ListNode* nodeToDelete = temp;
                temp = temp->next;
                delete nodeToDelete;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};
