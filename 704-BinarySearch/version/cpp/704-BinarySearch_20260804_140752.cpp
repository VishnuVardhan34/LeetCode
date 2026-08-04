// Last updated: 8/4/2026, 2:07:52 PM
// Binary Search
1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int l=0, r=nums.size()-1, mid=0;
5        while(l<=r) {
6            mid=(l+r)/2;
7            if(nums[mid]==target) {
8                return mid;
9            } else if(nums[mid]<target) {
10                l=mid+1;
11            } else {
12                r=mid-1;
13            }
14        }
15        return -1;
16    }
17};