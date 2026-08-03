use std::collections::HashSet;
impl Solution {
    pub fn check_if_pangram(sentence: String) -> bool {
        sentence.chars().collect::<HashSet<_>>().len() == 26
    }
}