// Last updated: 8/4/2026, 12:25:51 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Create a dummy node to simplify the merging process
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode* current = dummy;

    // Traverse both lists and merge them in sorted order
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // If there are remaining nodes in either list, append them
    if (list1 != NULL) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    // The merged list starts from the next node of the dummy
    struct ListNode* mergedList = dummy->next;
    
    // Free the dummy node and return the merged list
    free(dummy);
    return mergedList;
}
