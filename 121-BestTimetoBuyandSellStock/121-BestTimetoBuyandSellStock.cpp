// Last updated: 8/6/2026, 12:27:44 AM
1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int minPrice = INT_MAX, maxProfit = 0;
5        for (int &price: prices) {
6            minPrice = min(minPrice, price);
7            maxProfit = max(maxProfit, price - minPrice);
8        }
9        return maxProfit;
10    }
11};