// Last updated: 8/6/2026, 2:49:50 PM
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9class Solution {
10public:
11    ListNode *detectCycle(ListNode *head) {
12        unordered_set<ListNode*> seen;
13        while(head != nullptr) {
14            if(seen.count(head)) return head;
15            seen.insert(head);
16            head = head->next;
17        }
18        return nullptr;
19    }
20};