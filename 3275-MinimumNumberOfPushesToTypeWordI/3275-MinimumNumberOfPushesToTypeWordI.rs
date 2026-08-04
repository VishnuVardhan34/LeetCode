// Last updated: 8/4/2026, 12:22:38 PM
impl Solution {
    pub fn minimum_pushes(word: String) -> i32 {
        let n = word.len();
        let mut ans = 0;

        for i in 0..n {
            ans += (i / 8 + 1) as i32;
        }

        ans
    }
}