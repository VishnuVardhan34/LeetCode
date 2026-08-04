// Last updated: 8/4/2026, 8:08:07 PM
1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        if (nums.empty()) return 0;
5        sort(nums.begin(), nums.end());
6        return nums[0];
7    }
8};