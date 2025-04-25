/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *node = head;
    int count = 0;
    while (node != NULL && count < k) {
        node = node->next;
        count++;
    }
    if (count == k) {
        struct ListNode *prev = NULL;
        struct ListNode *curr = head;
        struct ListNode *next = NULL;
        int i = 0;
        while (i < k && curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }
        head->next = reverseKGroup(next, k);
        return (prev);
    }
    return (head);
}