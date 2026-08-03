impl Solution {
    pub fn minimum_pushes(word: String) -> i32 {
        // Creating a freq vector for 26 letters
        let mut freq = vec![0; 26];
        // Count the freqs in the word
        for ch in word.chars() {
            freq[(ch as u8 - b'a') as usize] += 1;
        }
        //sorting
        freq.sort_by(|a, b| b.cmp(a));
        let mut ans=0;
        for (i, &count) in freq.iter().enumerate() {
            if count ==0 {
                break;
            }
            let cost = (i / 8 + 1) as i32;
            ans += count * cost;
        }
        ans
    }
}