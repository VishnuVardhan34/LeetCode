// Last updated: 8/4/2026, 12:25:29 PM
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