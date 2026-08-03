class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest=0;
        for(int n: st){
            if (st.count(n-1)) continue;
            int curr = n;
            int length=1;
            while(st.count(curr+1)) {
                curr++;
                length++;
            }
            longest = max(longest, length);
        }
        return longest;
    }
};