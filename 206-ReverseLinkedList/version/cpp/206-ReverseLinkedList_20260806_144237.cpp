// Last updated: 8/6/2026, 2:42:37 PM
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* reverseList(ListNode* head) {
14        ListNode* prev = NULL;
15        ListNode* temp = head;
16        while(temp != nullptr) {
17            ListNode* front = temp->next;
18            temp->next = prev;
19            prev = temp;
20            temp = front;
21        }
22        return prev;
23    }
24};