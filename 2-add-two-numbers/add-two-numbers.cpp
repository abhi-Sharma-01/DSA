class Solution {
public:
    // Actually Don't Need it
    // ListNode* reverseLL(ListNode* head) {
    //     ListNode* curr = head;
    //     ListNode* prev = NULL;
    //     ListNode* nextNode = NULL;
        
    //     while (curr != NULL) {
    //         nextNode = curr->next; // Store next node
    //         curr->next = prev;     // Reverse link
    //         prev = curr;           // Move prev to next
    //         curr = nextNode;       // Move curr to next
    //     }
    //     return prev; // New head
    // }

    int sizeLL(ListNode* head) {
        int count = 0;
        while (head != NULL) {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (sizeLL(l1) < sizeLL(l2)) swap(l1, l2); // Actually ham kya kar rahe to maipulte in only one lisked list agar size kam hai toh ham swap kar rahe hai 
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* prev = NULL;// yah declare kiye taaki baad end m new node easily add kar sake
        int carry = 0;
        while (temp1 != NULL) {
            int sum = temp1->val + carry;
            if (temp2 != NULL) {
                sum += temp2->val;
                temp2 = temp2->next;
            }
            temp1->val = sum % 10;// here i try to store the One's digit only
            carry = sum / 10;
            prev = temp1; 
            temp1 = temp1->next;
        }
        if (carry > 0) {
            prev->next = new ListNode(carry);
        }
        return l1;
    }
};
