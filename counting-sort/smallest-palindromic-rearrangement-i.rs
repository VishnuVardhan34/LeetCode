impl Solution {
    pub fn smallest_palindrome(s: String) -> String {
        let mut freq = [0; 26];

        // Count the frequency of each character
        for ch in s.bytes() {
            freq[(ch - b'a') as usize] += 1;
        }

        let mut left = String::new();
        let mut middle = String::new();

        // Build the left half and find the middle character (if any)
        for i in 0..26 {
            let ch = (b'a' + i as u8) as char;

            for _ in 0..(freq[i] / 2) {
                left.push(ch);
            }

            if freq[i] % 2 == 1 {
                middle.push(ch);
            }
        }

        // Reverse the left half to form the right half
        let right: String = left.chars().rev().collect();

        // Construct the answer
        left + &middle + &right
    }
}