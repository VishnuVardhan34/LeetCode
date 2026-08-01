impl Solution {
    pub fn get_concatenation(nums: Vec<i32>) -> Vec<i32> {
        let size = nums.len();
        let mut ans = vec![0; 2 * size];
        for i in 0..size {
            ans[i] = nums[i];
            ans[i + size] = nums[i];
        }
        ans
    }
}