// Last updated: 8/4/2026, 5:00:11 PM
1class Solution {
2public:
3    vector<vector<int>> threeSum(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5
6        vector<vector<int>> ans;
7
8        for (int i = 0; i < nums.size() - 2; i++) {
9
10            if (nums[i] > 0)
11                break;
12
13            if (i > 0 && nums[i] == nums[i - 1])
14                continue;
15
16            int l = i + 1;
17            int r = nums.size() - 1;
18
19            while (l < r) {
20
21                int sum = nums[i] + nums[l] + nums[r];
22
23                if (sum < 0) {
24                    l++;
25                }
26                else if (sum > 0) {
27                    r--;
28                }
29                else {
30                    ans.push_back({nums[i], nums[l], nums[r]});
31
32                    l++;
33                    r--;
34
35                    while (l < r && nums[l] == nums[l - 1])
36                        l++;
37
38                    while (l < r && nums[r] == nums[r + 1])
39                        r--;
40                }
41            }
42        }
43
44        return ans;
45    }
46};