// Last updated: 8/4/2026, 12:23:18 PM
impl Solution {
    pub fn xor_operation(n: i32, start: i32) -> i32 {
        let mut xor = 0;
        for i in 0..n {
            xor ^= start + 2 * i;
        }
        xor
    }
}