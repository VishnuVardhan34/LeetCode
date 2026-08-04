// Last updated: 8/4/2026, 12:24:08 PM
use std::cmp;
impl Solution {
    pub fn predict_the_winner(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut d = vec![0; n+1];
        for i in 0..n {
            for j in 0..n-i {
                d[j] = cmp::max(nums[j] - d[j+1], nums[j+i] - d[j])
            }
        }
        return d[0] >= 0;
    }
}