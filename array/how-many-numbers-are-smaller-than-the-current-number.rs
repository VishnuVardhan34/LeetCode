use std::collections::HashMap;
impl Solution {
    pub fn smaller_numbers_than_current(nums: Vec<i32>) -> Vec<i32> {
        let mut sorted = nums.clone();
        sorted.sort();
        let mut ans = HashMap::new();
        for (idx, &num) in sorted.iter().enumerate() {
            ans.entry(num).or_insert(idx as i32);
        }
        nums.iter().map(|&num| ans[&num]).collect()
    }
}