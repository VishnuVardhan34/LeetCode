#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int min = *min_element(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());
        vector<int> ans;
        for (int i=min;i<max;i++) {
            if(st.find(i) == st.end()) ans.push_back(i);
        }
        return ans;
    }
};