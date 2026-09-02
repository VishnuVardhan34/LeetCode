class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr = 0, n = nums.size();
        for(int i = 0;i<n;i++) {
            xorr = xorr ^ nums[i];
        }
        return xorr;
    }
};