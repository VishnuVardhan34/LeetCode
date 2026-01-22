/*  Description:
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 
Example 1:

Input: head = [1,1,2]
Output: [1,2]
Example 2:


Input: head = [1,1,2,3,3]
Output: [1,2,3]

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.*/
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
    ListNode* deleteDuplicates(ListNode* head) {
        // Base case: if list is empty or has only one element
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* curr = head;

        // Traverse the list
        while (curr != nullptr && curr->next != nullptr) {
            // Since list is sorted, duplicates are always adjacent
            if (curr->val == curr->next->val) {
                // If current value equals next node's value, skip the next node
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp; // Good practice to free memory in C++
            } else {
                // Otherwise, move to the next node
                curr = curr->next;
            }
        }
        
        return head;
    }
};
