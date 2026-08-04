// Last updated: 8/4/2026, 12:24:13 PM
use std::collections::HashSet;
impl Solution {
    pub fn find_disappeared_numbers(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len() as i32;
        let mut ans: HashSet<i32> = (1..=n).collect();
        for num in nums {
            ans.remove(&num);
        }
        ans.into_iter().collect()
    }
}