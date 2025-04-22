/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummy;
    struct ListNode *prev = &dummy;
    dummy.next = head;
    while (prev->next && prev->next->next) {
        struct ListNode *first = prev->next;
        struct ListNode *second = first->next;
        first->next = second->next;
        second->next = first;
        prev->next = second;

        prev = first;
    }
    return (dummy.next);
}