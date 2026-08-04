// Last updated: 8/4/2026, 12:24:10 PM
impl Solution {
    pub fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {
        let mut c =0;
        let mut max_c =0;
        for i in nums {
            if i == 1 {
                c += 1;
            } else {
                max_c = max_c.max(c);
                c =0;
            }
        }
        max_c.max(c)
    }
}