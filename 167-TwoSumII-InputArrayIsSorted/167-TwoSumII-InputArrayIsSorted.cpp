// Last updated: 8/4/2026, 4:27:46 PM
1class Solution {
2public:
3    vector<int> twoSum(vector<int>& numbers, int target) {
4        int l=0,r=numbers.size()-1,sum=0;
5        while(l<r) {
6            sum = numbers[l] + numbers[r];
7            if (sum == target) {
8                return {l+1, r+1};
9            } else if(sum < target) {
10                l++;
11            } else {
12                r--;
13            }
14        }
15        return {};
16    }
17};