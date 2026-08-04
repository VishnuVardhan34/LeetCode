// Last updated: 8/4/2026, 12:24:19 PM
impl Solution {
    pub fn first_uniq_char(s: String) -> i32 {
        let mut freq = [0; 26];

        // Count frequencies
        for b in s.bytes() {
            freq[(b - b'a') as usize] += 1;
        }

        // Find first unique character
        for (i, b) in s.bytes().enumerate() {
            if freq[(b - b'a') as usize] == 1 {
                return i as i32;
            }
        }

        -1
    }
}