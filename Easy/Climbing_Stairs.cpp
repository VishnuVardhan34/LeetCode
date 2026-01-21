/*Description
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step*/
/* This challenge resembles the logic of Fibonacci sequence, so implement the sequence accordingly.

To know  the current vlaue you need to know the value of the previous two steps.

ways(3) = ways(2) + ways(1), But define the ways(1) and ways(2)*/

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n; // This condition takes care of stair count <= 2
        int l = 2;
        int bl = 1;
        // Apply the logic of Fibonacci series
        for(int i =3; i <= n; i++){
            int curr = l + bl;
            bl = l;
            l = curr;
        }
        return l;
    }
};