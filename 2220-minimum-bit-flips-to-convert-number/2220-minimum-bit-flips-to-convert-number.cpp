class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = start ^ goal, count = 0;
        for(int i=0;i<32;i++) {
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }
};