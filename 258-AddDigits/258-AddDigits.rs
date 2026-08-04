// Last updated: 8/4/2026, 12:24:22 PM
impl Solution {
    pub fn add_digits(num: i32) -> i32 {
        if num == 0 {
            0
        }
        else{
            1+(num-1)%9
        }
    }
}