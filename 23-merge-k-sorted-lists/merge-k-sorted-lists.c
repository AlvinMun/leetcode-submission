/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void swap(struct ListNode **a, struct ListNode **b) {
    struct ListNode *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct ListNode **heap, int heapSize, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < heapSize && heap[left]->val < heap[smallest]->val)
        smallest = left;
    if (right < heapSize && heap[right]->val < heap[smallest]->val)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, heapSize, smallest);
    }
}

void buildMinHeap(struct ListNode **heap, int heapSize) {
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        heapify(heap, heapSize, i);
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0)
        return NULL;
    struct ListNode **heap = malloc(sizeof(struct ListNode *) * listsSize);
    int heapSize = 0;
    for (int i = 0; i < listsSize; i++) {
        if (lists[i]) {
            heap[heapSize++] = lists[i];
        }
    }
    buildMinHeap(heap, heapSize);
    struct ListNode dummy;
    struct ListNode *tail = &dummy;
    dummy.next = NULL;
    while (heapSize > 0) {
        struct ListNode *minNode = heap[0];
        tail->next = minNode;
        tail = tail->next;
        
        if (minNode->next) {
            heap[0] = minNode->next;
        } else {
            heap[0] = heap[--heapSize];
        }
        heapify(heap, heapSize, 0);
    }
    free(heap);
    return (dummy.next);
}