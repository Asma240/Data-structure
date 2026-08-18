#include <stdlib.h>

/* LeetCode provides:
   struct ListNode {
       int val;
       struct ListNode *next;
   };
*/

/* Min-heap of ListNode* */
static void heap_swap(struct ListNode **a, struct ListNode **b) {
    struct ListNode *t = *a; *a = *b; *b = t;
}

static void heap_push(struct ListNode **heap, int *hsize, struct ListNode *node) {
    int i = (*hsize)++;
    heap[i] = node;
    /* sift up */
    while (i > 0) {
        int p = (i - 1) >> 1;
        if (heap[p]->val <= heap[i]->val) break;
        heap_swap(&heap[p], &heap[i]);
        i = p;
    }
}

static struct ListNode* heap_pop(struct ListNode **heap, int *hsize) {
    if (*hsize == 0) return NULL;
    struct ListNode *ret = heap[0];
    (*hsize)--;
    heap[0] = heap[*hsize];
    int i = 0;
    while (1) {
        int l = i * 2 + 1;
        int r = l + 1;
        if (l >= *hsize) break;
        int smallest = l;
        if (r < *hsize && heap[r]->val < heap[l]->val) smallest = r;
        if (heap[i]->val <= heap[smallest]->val) break;
        heap_swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
    return ret;
}

/* Merge k sorted lists using min-heap */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;

    /* allocate heap of size listsSize (at most k entries at a time) */
    struct ListNode **heap = (struct ListNode**)malloc(sizeof(struct ListNode*) * listsSize);
    if (!heap) return NULL;
    int hsize = 0;

    /* push first node of each non-empty list */
    for (int i = 0; i < listsSize; ++i) {
        if (lists[i]) heap_push(heap, &hsize, lists[i]);
    }

    struct ListNode dummy;
    struct ListNode *tail = &dummy;
    dummy.next = NULL;

    while (hsize > 0) {
        struct ListNode *node = heap_pop(heap, &hsize);
        /* append node to result */
        tail->next = node;
        tail = node;
        /* advance node in its list; if next exists, push into heap */
        if (node->next) heap_push(heap, &hsize, node->next);
        /* important: disconnect tail->next->next already points to next node; we keep links as-is */
    }

    struct ListNode *head = dummy.next;
    free(heap);
    return head;
}
