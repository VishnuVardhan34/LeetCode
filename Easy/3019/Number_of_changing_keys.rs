impl Solution {
    pub fn count_key_changes(s: String) -> i32 {
        let chars: Vec<_> = s.chars().collect();
        let mut c = 0;

        for i in 1..chars.len() {
            if !chars[i].eq_ignore_ascii_case(&chars[i-1]) {
                c += 1;
            }
        }
        c
    }