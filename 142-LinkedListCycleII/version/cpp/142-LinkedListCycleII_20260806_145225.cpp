// Last updated: 8/6/2026, 2:52:25 PM
1class Solution {
2public:
3    ListNode *detectCycle(ListNode *head) {
4        ListNode *slow = head;
5        ListNode *fast = head;
6
7        // Phase 1: Detect cycle
8        while (fast != nullptr && fast->next != nullptr) {
9            slow = slow->next;
10            fast = fast->next->next;
11
12            if (slow == fast) {
13                // Phase 2: Find cycle start
14                ListNode *ptr = head;
15
16                while (ptr != slow) {
17                    ptr = ptr->next;
18                    slow = slow->next;
19                }
20
21                return ptr;
22            }
23        }
24
25        return nullptr;
26    }
27};