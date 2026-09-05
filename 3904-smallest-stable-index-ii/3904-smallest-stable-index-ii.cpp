class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> PrefixMax(n);
        vector<int> SuffixMin(n);
        PrefixMax[0] = nums[0];
        for(int i=1;i<n;i++) {
            PrefixMax[i] = max(PrefixMax[i-1], nums[i]);
        }
        SuffixMin[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--) {
            SuffixMin[i] = min(SuffixMin[i+1], nums[i]);
        }
        for(int i=0;i<n;i++) {
            int ins = PrefixMax[i] - SuffixMin[i];
            if(ins <= k) {
                return i;
            }
        }
        return -1;
    }
};