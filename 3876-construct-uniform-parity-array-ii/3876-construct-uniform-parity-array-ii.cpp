class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());

        // Smallest element is odd.
        // It cannot change, and every even element
        // can subtract this odd number to become odd.
        if (nums1[0] % 2 == 1) {
            return true;
        }

        // Smallest element is even.
        // Therefore target must be even.
        // Odd elements cannot become even by subtracting
        // an even number.
        for (int i = 1; i < nums1.size(); i++) {
            if (nums1[i] % 2 == 1) {
                return false;
            }
        }

        return true;
    }
};