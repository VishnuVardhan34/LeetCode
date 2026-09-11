class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for(int d: digits) {
            freq[d]++;
        }
        int ans = 0;
        for(int num = 100; num <= 998; num+= 2) {
            int x = num;
            int ones = x % 10;
            x /= 10;
            int tens = x % 10;
            x /= 10;
            int hunderds = x;
            vector<int> used(10, 0);
            used[hunderds]++;
            used[tens]++;
            used[ones]++;
            bool possible = true;
            for(int d = 0;d <= 9; d++) {
                if(used[d] > freq[d]){
                    possible = false;
                    break;
                }
            }
            if(possible) {
                ans++;
            }
        }
        return ans;
    }
};