//--------------------------------
//Remove Linked List Elements
//--------------------------------

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* prev = &dummy;
    struct ListNode* current = head;
    
    while (current != NULL) {
        if (current->val == val) {
            prev->next = current->next;
        } else {
            prev = current;
        }
        current = current->next;  
    }

    return dummy.next;
}



//--------------------------------
//Reverse Linked List
//--------------------------------

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr != NULL) {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
