// Last updated: 8/4/2026, 12:23:24 PM
impl Solution {
    pub fn max_product(mut nums: Vec<i32>) -> i32 {
        nums.sort();

        let n = nums.len();
        (nums[n - 1] - 1) * (nums[n - 2] - 1)
    }
}