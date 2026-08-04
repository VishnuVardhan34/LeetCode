// Last updated: 8/4/2026, 12:21:55 PM
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        set<int> st(nums.begin(), nums.end());
        int a=nums[0];
        int b=nums.back();
        for(int i =a+1;i<=b-1;i++) {
            if(st.count(i)==0) ans.push_back(i);
        }
        return ans;
    }
};