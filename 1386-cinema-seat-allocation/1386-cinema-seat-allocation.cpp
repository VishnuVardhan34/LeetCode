class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;
        for(auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            mp[row] |= (1 << (col - 1));
        }
        int ans = (n - mp.size()) * 2;
        int left = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4);
        int mid = (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);
        int right = (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8);
        for (auto &[row, mask] : mp) {
            bool L = (mask & left) == 0;
            bool M = (mask & mid) == 0;
            bool R = (mask & right) == 0;

            if (L && R)
                ans += 2;
            else if (L || M || R)
                ans += 1;
        }
        return ans;
    }
};